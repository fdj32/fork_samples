package io.github.fdj32.repository;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import io.github.fdj32.entity.Customer;

@Repository
public interface CustomerRepository extends JpaRepository<Customer, Integer> {
}
