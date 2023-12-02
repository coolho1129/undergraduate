package com.knu.Team8Database.entity;

import jakarta.persistence.*;
import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
@Entity
@Table(name = "treats")
public class Treats {
    @Id
    @ManyToOne
    @JoinColumn(name = "medicine_id", nullable = false)
    private Medicine medicine;

    @Id
    @ManyToOne
    @JoinColumn(name = "symptom_id", nullable = false)
    private Symptom symptom;
}