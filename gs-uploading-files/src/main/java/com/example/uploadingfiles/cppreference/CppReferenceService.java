package com.example.uploadingfiles.cppreference;

import java.io.File;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
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
	private static final String FOLDER = "D:/logs/cppreference";

	private static final Logger log = LoggerFactory.getLogger(CppReferenceService.class.getSimpleName());

	private static final int RETRY_TIMES = 3;
	private static final int MAX_URL = 30000;
	private static final int MAX_STACK_DEPTH = 10;

	private static final ConcurrentMap<String, Boolean> urlMap = new ConcurrentHashMap<>();

	public void run() {
		run("", 0);
		urlMap.keySet().stream().forEach(System.out::println);
	}

	public void run(String url, int stackDepth) {
		if (stackDepth > MAX_STACK_DEPTH) {
			return;
		}
		if (null != urlMap.get(url) && urlMap.get(url))
			return;
		if (urlMap.size() > MAX_URL) {
			return;
		}
		Document doc = connect(HOST + url);
		if (null == doc)
			return;
		Elements elements = doc.select("a");
		elements.stream().forEach(e -> {
			String href = e.attr("href");
			if (href.startsWith("/w/c") && -1 == href.indexOf("#")) {
				if (null == urlMap.get(href)) {
					urlMap.put(href, false);
				}
				if (0 == urlMap.size() % 100) {
					log.info("size = {}", urlMap.size());
				}
			}
		});
		sourceCode(url, doc);
		urlMap.put(url, true);
		urlMap.keySet().stream().filter(i -> !urlMap.get(i)).forEach(i -> run(i, stackDepth + 1));
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
		log.info("connect({})", url);
		Document doc = null;
		int times = 1;
		while (times <= RETRY_TIMES) {
			try {
				Connection conn = HttpConnection.connect(url);
				doc = conn.get();
			} catch (IOException e) {
				log.error("connect({}) fail {} times", url, times);
			}
			if (null != doc)
				break;
			else
				times++;
		}
		return doc;
	}

}
