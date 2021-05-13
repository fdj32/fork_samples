package com.active.vault.util;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.stereotype.Service;
import org.springframework.vault.core.VaultOperations;
import org.springframework.vault.support.Ciphertext;
import org.springframework.vault.support.Plaintext;
import org.springframework.vault.support.VaultTransitKey;

import java.util.List;
import java.util.stream.Collectors;

@Service
@ConfigurationProperties
public class TransitConverter {

    private static final Logger LOGGER = LoggerFactory.getLogger(TransitConverter.class);

    @Autowired
    private VaultOperations vaultOperations;

    @Value("${vault.transit.key.customer}")
    private String customer;

    public String convertToDatabaseColumn(String sin) {
        Plaintext plaintext = Plaintext.of(sin);
        String s = vaultOperations.opsForTransit().encrypt(customer, plaintext).getCiphertext();
        LOGGER.debug("convertToDatabaseColumn({}) = {}", sin, s);
        return s;
    }

    public String convertToEntityAttribute(String sin) {
        Ciphertext ciphertext = Ciphertext.of(sin);
        String s = vaultOperations.opsForTransit().decrypt(customer, ciphertext).asString();
        LOGGER.debug("convertToEntityAttribute({}) = {}", sin, s);
        return s;
    }

    public List<String> encryptBatch(List<String> list) {
        List<Plaintext> plainTextList = list.stream().map(i -> Plaintext.of(i)).collect(Collectors.toList());
        return vaultOperations.opsForTransit().encrypt(customer, plainTextList).stream().map(i -> i.get().getCiphertext()).collect(Collectors.toList());
    }

    public List<String> decryptBatch(List<String> list) {
        List<Ciphertext> cipherTextList = list.stream().map(i -> Ciphertext.of(i)).collect(Collectors.toList());
        return vaultOperations.opsForTransit().decrypt(customer, cipherTextList).stream().map(i -> i.get().asString()).collect(Collectors.toList());
    }

    public void rotate() {
        vaultOperations.opsForTransit().rotate(customer);
    }

    public VaultTransitKey getKey() {
        return vaultOperations.opsForTransit().getKey(customer);
    }

    /**
     * This function doesn't support batch, we suggest you to use rewrapBatch, which combines decryptBatch with old key (see the key version in ciphertext) & encryptBatch with new key (by default).
     * @param previous
     * @return
     */
    public String rewrap(String previous) {
        return vaultOperations.opsForTransit().rewrap(customer, previous);
    }

    public List<String> rewrapBatch(List<String> list) {
        return encryptBatch(decryptBatch(list));
    }
}
