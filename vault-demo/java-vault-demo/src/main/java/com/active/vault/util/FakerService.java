package com.active.vault.util;

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.UUID;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.active.vault.entity.Customer;
import com.active.vault.entity.SecurityQuestionAnswer;
import com.active.vault.repository.CustomerRepository;
import com.active.vault.repository.SecurityQuestionAnswerRepository;
import com.github.javafaker.Faker;
import com.github.javafaker.Name;

@Service
public class FakerService {

    private static final Logger LOGGER = LoggerFactory.getLogger(FakerService.class);

    @Autowired
    private CustomerRepository customerRepository;

    @Autowired
    private SecurityQuestionAnswerRepository securityQuestionAnswerRepository;

    @Autowired
    private TransitConverter transitConverter;

    public void generate(int num) {
        SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");
        List<Customer> customers = new ArrayList<>();
        List<SecurityQuestionAnswer> securityQuestionAnswers = new ArrayList<>();
        List<String> plainList = new ArrayList<>();
        Faker faker = null;
        for (int i = 0; i < num; i++) {
            faker = new Faker();
            Name fakeName = faker.name();
            String fname = fakeName.firstName();
            String lname = fakeName.lastName();
            String name = fname + lname;
            String pwd = UUID.randomUUID().toString().substring(0, 8);
            String birth = sdf.format(faker.date().birthday());
            String weight = String.format("%.1f", (60 + 10 * Math.random()));
            String email = fname + "." + lname + "@" + faker.internet().emailAddress().split("@")[1];
            plainList.addAll(Arrays.asList(birth, email, pwd, weight));
            customers.add(new Customer(name, pwd, fname, lname, birth, weight, email));
        }
        List<String> cipherList = transitConverter.encryptBatch(plainList);
        for (int i = 0; i < num; i++) {
            customers.get(i).setBirth(cipherList.get(i * 4));
            customers.get(i).setEmail(cipherList.get(i * 4 + 1));
            customers.get(i).setPwd(cipherList.get(i * 4 + 2));
            customers.get(i).setWeight(cipherList.get(i * 4 + 3));
        }
        customers = customerRepository.saveAll(customers);

        plainList.clear();
        cipherList.clear();

        for (int i = 0; i < num; i++) {
            faker = new Faker();
            if (Math.random() > 0.3) {
                plainList.addAll(Arrays.asList("Who is your favorite artist?", faker.artist().name()));
                securityQuestionAnswers.add(new SecurityQuestionAnswer(customers.get(i).getId(), "", ""));
            }
            if (Math.random() > 0.3) {
                plainList.addAll(Arrays.asList("What is your favorite music instrument?", faker.music().instrument()));
                securityQuestionAnswers.add(new SecurityQuestionAnswer(customers.get(i).getId(), "", ""));
            }
            if (Math.random() > 0.3) {
                plainList.addAll(Arrays.asList("What is your favorite color?", faker.color().name()));
                securityQuestionAnswers.add(new SecurityQuestionAnswer(customers.get(i).getId(), "", ""));
            }
            if (Math.random() > 0.3) {
                plainList.addAll(Arrays.asList("What is your job title?", faker.job().title()));
                securityQuestionAnswers.add(new SecurityQuestionAnswer(customers.get(i).getId(), "", ""));
            }
            if (Math.random() > 0.3) {
                plainList.addAll(Arrays.asList("What is your favorite animal?", faker.animal().name()));
                securityQuestionAnswers.add(new SecurityQuestionAnswer(customers.get(i).getId(), "", ""));
            }
        }

        cipherList = transitConverter.encryptBatch(plainList);
        for (int i = 0; i < securityQuestionAnswers.size(); i++) {
            securityQuestionAnswers.get(i).setQuestion(cipherList.get(i * 2));
            securityQuestionAnswers.get(i).setAnswer(cipherList.get(i * 2 + 1));
        }
        securityQuestionAnswerRepository.saveAll(securityQuestionAnswers);

        long count = customerRepository.count();
        LOGGER.info("customer size: {}", count);
        count = securityQuestionAnswerRepository.count();
        LOGGER.info("securityQuestionAnswer size: {}", count);
    }

}
