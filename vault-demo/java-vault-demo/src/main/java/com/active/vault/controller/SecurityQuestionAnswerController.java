package com.active.vault.controller;

import com.active.vault.entity.SecurityQuestionAnswer;
import com.active.vault.repository.SecurityQuestionAnswerRepository;
import com.active.vault.util.TransitConverter;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.data.domain.Example;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.PageRequest;
import org.springframework.http.MediaType;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.*;
import java.util.stream.Collectors;

@RestController
@RequestMapping("/apis/sqa")
@ConfigurationProperties
public class SecurityQuestionAnswerController {

    private static final Logger LOGGER = LoggerFactory.getLogger(SecurityQuestionAnswerController.class);

    @Autowired
    private TransitConverter transitConverter;

    @Autowired
    private SecurityQuestionAnswerRepository securityQuestionAnswerRepository;

    @Value("${app.page.size}")
    private int size;

    @GetMapping(path = "/customer/{id}", produces = MediaType.APPLICATION_JSON_VALUE)
    public List<SecurityQuestionAnswer> question(@PathVariable("id") Integer id) {
        LOGGER.info("/apis/sqa/customer/{}", id);
        SecurityQuestionAnswer sqa = new SecurityQuestionAnswer();
        sqa.setCustomer(id);
        List<SecurityQuestionAnswer> result = securityQuestionAnswerRepository.findAll(Example.of(sqa));
        if (null == result || result.isEmpty())
            return null;

        List<String> columns = new ArrayList<>();
        for (int i = 0; i < result.size(); i++) {
            columns.addAll(Arrays.asList(result.get(i).getQuestion(), result.get(i).getAnswer()));
        }
        List<String> list = transitConverter.decryptBatch(columns);
        for (int i = 0; i < result.size(); i++) {
            result.get(i).setQuestion(list.get(i * 2));
            result.get(i).setAnswer(list.get(i * 2 + 1));
        }
        return result;
    }

    @GetMapping(path = "/page/{page}", produces = MediaType.APPLICATION_JSON_VALUE)
    public Page<SecurityQuestionAnswer> page(@PathVariable("page") Integer page) {
        LOGGER.info("/apis/sqa/page/{}", page);
        Page<SecurityQuestionAnswer> result = securityQuestionAnswerRepository.findAll(PageRequest.of(page, size));
        List<String> columns = new ArrayList<>();
        result.getContent().forEach(i -> {
            columns.addAll(Arrays.asList(i.getQuestion(), i.getAnswer()));
        });
        List<String> list = transitConverter.decryptBatch(columns);
        for (int i = 0; i < result.getContent().size(); i++) {
            result.getContent().get(i).setQuestion(list.get(i * 2));
            result.getContent().get(i).setAnswer(list.get(i * 2 + 1));
        }
        return result;
    }

    @GetMapping(path = "/stat", produces = MediaType.APPLICATION_JSON_VALUE)
    public Map<String, Long> stat() {
        return statistics();
    }

    @GetMapping(path = "/rewrap", produces = MediaType.APPLICATION_JSON_VALUE)
    public Map<String, Long> rewrap() {
        rotate();
        return statistics();
    }

    private void rotate() {
        Page<SecurityQuestionAnswer> p = securityQuestionAnswerRepository.findAll(PageRequest.of(0, size));
        int totalPages = p.getTotalPages();
        for (int j = 0; j < totalPages; j++) {
            if (null == p)
                p = securityQuestionAnswerRepository.findAll(PageRequest.of(j, size));
            final List<String> columns = new ArrayList<>();
            p.getContent().forEach(i -> {
                columns.addAll(Arrays.asList(i.getQuestion(), i.getAnswer()));
            });
            List<String> list = transitConverter.rewrapBatch(columns);

            for (int i = 0; i < p.getContent().size(); i++) {
                p.getContent().get(i).setQuestion(list.get(i * 2));
                p.getContent().get(i).setAnswer(list.get(i * 2 + 1));
            }
            securityQuestionAnswerRepository.saveAll(p.getContent());
            p = null;
        }
    }

    private Map<String, Long> statistics() {
        // // In case of OOM!!!
        // return securityQuestionAnswerRepository.findAll().stream().collect(Collectors.groupingBy(i -> i.getQuestion().split(":")[1], Collectors.counting()));

        Map<String, Long> result = new HashMap<>();
        Page<SecurityQuestionAnswer> p = securityQuestionAnswerRepository.findAll(PageRequest.of(0, size));
        int totalPages = p.getTotalPages();
        for (int j = 0; j < totalPages; j++) {
            if (null == p)
                p = securityQuestionAnswerRepository.findAll(PageRequest.of(j, size));
            p.getContent().stream().collect(Collectors.groupingBy(i -> i.getQuestion().split(":")[1], Collectors.counting())).entrySet().forEach(e -> {
                Long existValue = result.get(e.getKey());
                result.put(e.getKey(), e.getValue() + (null == existValue ? 0 : existValue));
            });
            p = null;
        }
        return result;
    }

}
