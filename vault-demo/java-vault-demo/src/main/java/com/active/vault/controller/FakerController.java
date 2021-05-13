package com.active.vault.controller;

import com.active.vault.util.FakerService;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.Collections;
import java.util.Map;

@RestController
@RequestMapping("/apis/faker")
public class FakerController {

    private static final Logger LOGGER = LoggerFactory.getLogger(FakerController.class);

    @Autowired
    private FakerService fakerService;

    @GetMapping(path = "/generate/{num}")
    public Map<String, Integer> generate(@PathVariable("num") Integer num) {
        LOGGER.info("/apis/faker/generate/{}", num);
        fakerService.generate(num);
        return Collections.singletonMap("generated", num);
    }
}
