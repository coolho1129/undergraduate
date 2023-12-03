package com.knu.Team8Database.entity;

import jakarta.persistence.*;
import lombok.Getter;
import lombok.Setter;

import java.util.Date;
import java.util.List;
@Getter
@Setter
@Entity
@Table(name = "users")
public class User {
    @Id
    @Column(name = "user_id", nullable = false, columnDefinition = "NVARCHAR2(20)")
    private String userId;

    @Column(name = "name", nullable = false, columnDefinition = "NVARCHAR2(20)")
    private String name;

    @Column(name = "birth")
    @Temporal(TemporalType.DATE)
    private Date birth;

    @Column(name = "password", nullable = false, columnDefinition = "NVARCHAR2(20)")
    private String password;

    @Column(name = "gender", length = 1)
    private Character gender;

    @OneToMany(mappedBy = "user")
    private List<Review> reviews;

    @OneToMany(mappedBy = "user")
    private List<Finds> finds;

}
