package com.knu.Team8Database.entity;

import jakarta.persistence.*;
import lombok.Getter;
import lombok.Setter;

import java.util.List;

@Getter
@Setter
@Entity
@Table(name = "symptom")
public class Symptom {
    @Id
    @Column(name = "symptom_id", nullable = false, length = 5)
    private String symptomId;

    @Column(name = "name", nullable = false, columnDefinition = "NVARCHAR2(15)")
    private String name;

    @Column(name = "field", columnDefinition = "NVARCHAR2(15)")
    private String field;

    @OneToMany(mappedBy = "symptom")
    private List<Treats> treats;

}