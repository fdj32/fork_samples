package com.active.vault.entity;

import com.active.vault.util.TransitConverter;

import javax.persistence.*;
import java.io.Serializable;

@Entity
@Table(name = "security_question_answer")
public class SecurityQuestionAnswer implements Serializable {

    private Integer id;
    private Integer customer;
    @Convert(converter = TransitConverter.class)
    private String question;
    @Convert(converter = TransitConverter.class)
    private String answer;

    public SecurityQuestionAnswer() {
    }

    public SecurityQuestionAnswer(Integer customer, String question, String answer) {
        this.customer = customer;
        this.question = question;
        this.answer = answer;
    }

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public Integer getCustomer() {
        return customer;
    }

    public void setCustomer(Integer customer) {
        this.customer = customer;
    }

    public String getQuestion() {
        return question;
    }

    public void setQuestion(String question) {
        this.question = question;
    }

    public String getAnswer() {
        return answer;
    }

    public void setAnswer(String answer) {
        this.answer = answer;
    }
}
