package com.example.uploadingfiles.cppreference;

import java.io.File;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.util.HashSet;
import java.util.Set;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ConcurrentMap;

import org.apache.commons.io.FileUtils;
import org.jsoup.Connection;
import org.jsoup.helper.HttpConnection;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.stereotype.Service;

@Service
public class CppReferenceService {

	private static final String HOST = "https://en.cppreference.com";
	private static final String OS_NAME = System.getProperty("os.name"); // "Mac OS X", "Linux", "Windows 10"
	private static final String FOLDER_Windows = "C:/logs/cppreference";
	private static final String FOLDER_Mac_OS_X = "/Users/nfeng/logs/cppreference";
	private static final String FOLDER_Linux = "/home/nfeng/logs/cppreference";
	private static final String FOLDER = -1 != OS_NAME.indexOf("Linux") ? FOLDER_Linux
			: (-1 != OS_NAME.indexOf("Mac") ? FOLDER_Mac_OS_X
					: (-1 != OS_NAME.indexOf("Windows") ? FOLDER_Windows : "/tmp/cppreference"));
	private static final String URL_LINES = "/url_lines.txt";

	private static final Logger log = LoggerFactory.getLogger(CppReferenceService.class.getSimpleName());

	private static final int RETRY_TIMES = 3;
	private static final int MAX_URL = 10000;
	private static final int MAX_LOOPS = 10;

	private static final ConcurrentMap<String, Boolean> urlMap = new ConcurrentHashMap<>();
	private static final Set<String> urlSet = new HashSet<>();

	public void run() throws IOException {
		urlSet.add("");
		for (int i = 0; i < MAX_LOOPS; i++) {
			int startSize = urlSet.size();
			log.info("loop {} start, size: {}", i, startSize);
			urlSet.addAll(urlMap.keySet());
			urlSet.parallelStream().forEach(j -> run(j));
			urlSet.addAll(urlMap.keySet());
			int endSize = urlSet.size();
			log.info("loop {} end, size: {}", i, endSize);
			if (startSize == endSize) {
				log.info("No more new url found");
				break;
			}
		}
		String lines = urlSet.stream().reduce("", (i, j) -> i + System.lineSeparator() + j);
		System.out.println(lines);
		FileUtils.write(new File(FOLDER + URL_LINES), lines, StandardCharsets.UTF_8);
	}

	public void run(String url) {
		if (null != urlMap.get(url) && urlMap.get(url)) {
			return;
		}
		if (urlMap.size() > MAX_URL) {
			log.info("max url exceed", MAX_URL);
			return;
		}
		Document doc = connect(HOST + url);
		if (null == doc)
			return;
		sourceCode(url, doc);
		urlMap.put(url, true);
		Elements elements = doc.select("a");
		elements.parallelStream().filter(e -> null != e.attr("href") && e.attr("href").startsWith("/w/c")
				&& -1 == e.attr("href").indexOf("#") && null == urlMap.get(e.attr("href"))).forEach(e -> {
					String href = e.attr("href");
					urlMap.put(href, false);
					if (0 == urlMap.size() % 20) {
						log.info("size = {}", urlMap.size());
					}
				});
	}

	private void sourceCode(String url, Document doc) {
		Elements elements = doc.select(sourceSelector(url));
		if (0 == elements.size())
			return;
		for (int i = 0; i < elements.size(); i++) {
			Element e = elements.get(i);
			String content = sourceText(e);
			if (-1 == content.indexOf("main"))
				return;
			String fileName = FOLDER + url + (elements.size() > 1 ? (i + 1) + "" : "") + fileExtention(url);
			try {
				writeFile(fileName, content);
			} catch (IOException e1) {
				log.error("write source file {} failed", url);
			}
		}
	}

	private void writeFile(String fileName, String content) throws IOException {
		File file = new File(fileName);
		FileUtils.createParentDirectories(file);
		FileUtils.writeStringToFile(file, content, StandardCharsets.UTF_8);
	}

	private String sourceText(Element e) {
		String s = e.toString();
		s = s.replaceAll("<div class=\\\"c(pp)? source-c(pp)?\\\">", "");
		s = s.replaceAll("</div>", "");
		s = s.replaceAll("<pre class=\\\"de1\\\">", "");
		s = s.replaceAll("</pre>", "");
		s = s.replaceAll("<span class=\\\"\\w{3,10}\\\">", "");
		s = s.replaceAll("</span>", "");
		s = s.replaceAll("<a href=\\\".{2,100}\\\">", "");
		s = s.replaceAll("</a>", "");
		s = s.replaceAll("&nbsp;", "");
		s = s.replaceAll("&lt;", "<");
		s = s.replaceAll("&gt;", ">");
		s = s.replaceAll("&amp;", "&");
		return s;
	}

	private String sourceSelector(String url) {
		if (url.startsWith("/w/c/")) {
			return "div [class=c source-c]";
		} else {
			return "div [class=cpp source-cpp]";
		}
	}

	private String fileExtention(String url) {
		if (url.startsWith("/w/c/")) {
			return ".c";
		} else {
			return ".cpp";
		}
	}

	private Document connect(String url) {
		Document doc = null;
		int times = 1;
		while (times <= RETRY_TIMES) {
			try {
				Connection conn = HttpConnection.connect(url);
				doc = conn.get();
			} catch (IOException e) {
				if (times < RETRY_TIMES) {
					log.debug("connect({}) fail {} times", url, times);
				} else {
					log.error("connect({}) fail {} times", url, times);
				}
			}
			if (null != doc)
				break;
			else
				times++;
		}
		return doc;
	}

}
