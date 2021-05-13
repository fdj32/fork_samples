package com.active.vault.repository;

import com.active.vault.entity.SecurityQuestionAnswer;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface SecurityQuestionAnswerRepository extends JpaRepository<SecurityQuestionAnswer, Integer> {
}
