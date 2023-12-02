package com.knu.Team8Database.entity;

import jakarta.persistence.*;
import lombok.Getter;
import lombok.Setter;

import java.util.Date;
import java.util.List;

@Getter
@Setter
@Entity
@Table(name = "medicine")
public class Medicine {
    @Id
    @Column(name = "medicine_id", nullable = false, length = 5)
    private String medicineId;

    @ManyToOne
    @JoinColumn(name = "company_id", nullable = false)
    private Company company;

    @Column(name = "name", nullable = false,  columnDefinition = "NVARCHAR2(120)")
    private String name;

    @Column(name = "capacity", columnDefinition = "NVARCHAR2(30)")
    private String capacity;

    @Column(name = "price", columnDefinition = "NUMBER")
    private Double price;

    @Column(name = "manufacture_date", columnDefinition = "DATE")
    @Temporal(TemporalType.DATE)
    private Date manufactureDate;

    @OneToMany(mappedBy = "medicine")
    private List<Review> reviews;

    @OneToMany(mappedBy = "medicine")
    private List<Finds> finds;

    @OneToMany(mappedBy = "medicine")
    private List<Includes> includes;

    @OneToMany(mappedBy = "medicine")
    private List<Treats> treats;

}

