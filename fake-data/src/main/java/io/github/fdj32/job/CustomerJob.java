package io.github.fdj32.job;

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.List;
import java.util.UUID;
import java.util.stream.IntStream;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.scheduling.annotation.Scheduled;
import org.springframework.stereotype.Component;

import com.github.javafaker.Faker;
import com.github.javafaker.Name;

import io.github.fdj32.entity.Customer;
import io.github.fdj32.repository.CustomerRepository;

@Component
public class CustomerJob {

	private static final Logger LOG = LoggerFactory.getLogger(CustomerJob.class);

	@Autowired
	private CustomerRepository customerRepository;

	@Scheduled(fixedRate = 3000)
	public void insertBatch() {
		LOG.info("insertBatch");

		List<Customer> list = new ArrayList<>();
		IntStream.range(0, 1000).forEach(i -> {
			list.add(genCust());
		});
		customerRepository.saveAll(list);
	}

	@Scheduled(fixedRate = 1000)
	public void insertSingle() {
		LOG.info("insertSingle");
		customerRepository.save(genCust());
	}

	@Scheduled(fixedRate = 10000)
	public void count() {
		LOG.info("count: {}", customerRepository.count());
	}

	private Customer genCust() {
		SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");
		Faker faker = new Faker();
		Name fakeName = faker.name();
		String fname = fakeName.firstName();
		String lname = fakeName.lastName();
		String name = fname + " " + lname;
		String pwd = UUID.randomUUID().toString().substring(0, 8);
		String birth = sdf.format(faker.date().birthday());
		String weight = String.format("%.1f", (60 + 10 * Math.random()));
		String email = fname + "." + lname + "@" + faker.internet().emailAddress().split("@")[1];
		return new Customer(name, pwd, fname, lname, birth, weight, email);
	}
}
