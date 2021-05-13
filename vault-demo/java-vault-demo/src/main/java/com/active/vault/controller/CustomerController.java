package com.active.vault.controller;

import com.active.vault.entity.Customer;
import com.active.vault.repository.CustomerRepository;
import com.active.vault.util.TransitConverter;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.boot.context.properties.ConfigurationProperties;
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
@RequestMapping("/apis/customer")
@ConfigurationProperties
public class CustomerController {
    private static final Logger LOGGER = LoggerFactory.getLogger(CustomerController.class);

    @Autowired
    private TransitConverter transitConverter;

    @Autowired
    private CustomerRepository customerRepository;

    @Value("${app.page.size}")
    private int size;

    @GetMapping(path = "/{id}", produces = MediaType.APPLICATION_JSON_VALUE)
    public Customer findById(@PathVariable("id") Integer id) {
        LOGGER.info("/apis/customer/{}", id);
        Optional<Customer> optional = customerRepository.findById(id);
        if (!optional.isPresent())
            return null;
        Customer i = optional.get();
        List<String> list = transitConverter.decryptBatch(Arrays.asList(i.getBirth(), i.getEmail(), i.getPwd(), i.getWeight()));
        i.setBirth(list.get(0));
        i.setEmail(list.get(1));
        i.setPwd(list.get(2));
        i.setWeight(list.get(3));
        return i;
    }

    @GetMapping(path = "/page/{page}", produces = MediaType.APPLICATION_JSON_VALUE)
    public Page<Customer> page(@PathVariable("page") Integer page) {
        LOGGER.info("/apis/customer/page/{}", page);
        Page<Customer> result = customerRepository.findAll(PageRequest.of(page, size));
        List<String> columns = new ArrayList<>();
        result.getContent().forEach(i -> {
            columns.addAll(Arrays.asList(i.getBirth(), i.getEmail(), i.getPwd(), i.getWeight()));
        });
        List<String> list = transitConverter.decryptBatch(columns);
        for (int i = 0; i < result.getContent().size(); i++) {
            result.getContent().get(i).setBirth(list.get(i * 4));
            result.getContent().get(i).setEmail(list.get(i * 4 + 1));
            result.getContent().get(i).setPwd(list.get(i * 4 + 2));
            result.getContent().get(i).setWeight(list.get(i * 4 + 3));
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
        Page<Customer> p = customerRepository.findAll(PageRequest.of(0, size));
        int totalPages = p.getTotalPages();
        for (int j = 0; j < totalPages; j++) {
            if (null == p)
                p = customerRepository.findAll(PageRequest.of(j, size));
            final List<String> columns = new ArrayList<>();
            p.getContent().forEach(i -> {
                columns.addAll(Arrays.asList(i.getBirth(), i.getEmail(), i.getPwd(), i.getWeight()));
            });
            List<String> list = transitConverter.rewrapBatch(columns);

            for (int i = 0; i < p.getContent().size(); i++) {
                p.getContent().get(i).setBirth(list.get(i * 4));
                p.getContent().get(i).setEmail(list.get(i * 4 + 1));
                p.getContent().get(i).setPwd(list.get(i * 4 + 2));
                p.getContent().get(i).setWeight(list.get(i * 4 + 3));
            }
            customerRepository.saveAll(p.getContent());
            p = null;
        }
    }

    private Map<String, Long> statistics() {
        // In case of OOM!!!
        // return customerRepository.findAll().stream().collect(Collectors.groupingBy(i -> i.getBirth().split(":")[1], Collectors.counting()));

        Map<String, Long> result = new HashMap<>();
        Page<Customer> p = customerRepository.findAll(PageRequest.of(0, size));
        int totalPages = p.getTotalPages();
        for (int j = 0; j < totalPages; j++) {
            if (null == p)
                p = customerRepository.findAll(PageRequest.of(j, size));
            p.getContent().stream().collect(Collectors.groupingBy(i -> i.getBirth().split(":")[1], Collectors.counting())).entrySet().forEach(e -> {
                Long existValue = result.get(e.getKey());
                result.put(e.getKey(), e.getValue() + (null == existValue ? 0 : existValue));
            });
            p = null;
        }
        return result;
    }

}
