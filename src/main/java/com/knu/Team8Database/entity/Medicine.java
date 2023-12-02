package com.knu.Team8Database.entity;

import jakarta.persistence.*;

@Entity
@Table(name = "medicine")
public class Medicine {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private int medicine_id;

    @Column(nullable = false)
    private String name;
}
