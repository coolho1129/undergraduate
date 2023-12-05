package com.knu.Team8Database.entity;

import jakarta.persistence.*;
import lombok.*;

import java.util.Date;
import java.util.List;
@Getter
@Setter
@Builder
@AllArgsConstructor
@NoArgsConstructor(access = AccessLevel.PROTECTED)
@Entity
@Table(name = "users")
public class Users {
    @Id
    @Column(name = "user_id", nullable = false, columnDefinition = "NVARCHAR2(20)")
    private String usersId;

    @Column(name = "name", nullable = false, columnDefinition = "NVARCHAR2(20)")
    private String usersName;

    @Column(name = "birth")
    @Temporal(TemporalType.DATE)
    private Date usersBirth;

    @Column(name = "password", nullable = false, columnDefinition = "NVARCHAR2(20)")
    private String usersPassword;

    @Column(name = "gender", length = 1)
    private Character usersGender;

    @OneToMany(mappedBy = "usersId")
    private List<Review> reviews;

    @OneToMany(mappedBy = "usersId")
    private List<Finds> finds;

}