package com.knu.Team8Database.entity;

import jakarta.persistence.*;
import lombok.Getter;
import lombok.Setter;

import java.util.List;

@Getter
@Setter
@Entity
@Table(name = "company")
public class Company {
    @Id
    @Column(name = "company_id", nullable = false, length = 5)
    private String companyId;

    @Column(name = "name", nullable = false, columnDefinition = "NVARCHAR2(15)")
    private String name;

    @Column(name = "phone_number", columnDefinition = "VARCHAR2(15)")
    private String phoneNumber;

    @Column(name = "website", columnDefinition = "NVARCHAR2(50)")
    private String website;

    @OneToMany(mappedBy = "company")
    private List<Medicine> medicines;

}