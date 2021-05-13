package com.active.vault.controller;

import com.active.vault.util.TransitConverter;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.MediaType;
import org.springframework.vault.support.VaultTransitKey;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/apis/vault/transit")
public class VaultTransitController {

    private static final Logger LOGGER = LoggerFactory.getLogger(CustomerController.class);

    @Autowired
    private TransitConverter transitConverter;

    @GetMapping(path = "/getKey", produces = MediaType.APPLICATION_JSON_VALUE)
    public VaultTransitKey getKey() {
        LOGGER.info("/apis/vault/transit/getKey");
        return transitConverter.getKey();
    }

    @GetMapping(path = "/rotate", produces = MediaType.APPLICATION_JSON_VALUE)
    public VaultTransitKey rotate() {
        LOGGER.info("/apis/vault/transit/rotate");
        transitConverter.rotate();
        return transitConverter.getKey();
    }
}
