package com.knu.Team8Database.entity;

import jakarta.persistence.*;
import lombok.Getter;
import lombok.Setter;

import java.util.List;

@Getter
@Setter
@Entity
@Table(name = "admin")
public class Admin {
    @Id
    @Column(name = "admin_id", nullable = false, columnDefinition = "NVARCHAR2(20)")
    private String adminId;

    @Column(name = "name", nullable = false, columnDefinition = "NVARCHAR2(20)")
    private String name;

    @Column(name = "password", nullable = false, columnDefinition = "NVARCHAR2(20)")
    private String password;

    @OneToMany(mappedBy = "admin")
    private List<Review> reviews;

}