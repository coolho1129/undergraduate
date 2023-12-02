package com.knu.Team8Database.entity;

import jakarta.persistence.*;
import lombok.Getter;
import lombok.Setter;

import java.util.Date;
import java.util.List;

@Getter
@Setter
@Entity
public class Detail_view {

    @Id
    @Column(name = "medicineId", nullable = false, length = 5)
    private String medicineId;

    @Column(name = "medicineName", nullable = false,  columnDefinition = "NVARCHAR2(120)")
    private String medicineName;

    @Column(name = "medicineCapacity", columnDefinition = "NVARCHAR2(30)")
    private String medicineCapacity;

    @Column(name = "medicinePrice", columnDefinition = "NUMBER")
    private Integer medicinePrice;

    @Column(name = "medicineManufactureDate", columnDefinition = "DATE")
    @Temporal(TemporalType.DATE)
    private Date medicineManufactureDate;

    @Column(name = "companyName", nullable = false, columnDefinition = "NVARCHAR2(15)")
    private String companyName;

    @Column(name = "companyPhoneNumber", columnDefinition = "VARCHAR2(15)")
    private String companyPhoneNumber;

    @Column(name = "companyWebsite", columnDefinition = "NVARCHAR2(50)")
    private String companyWebsite;

    @Column(name = "symtomField", columnDefinition = "NVARCHAR2(15)")
    private String symtomField;

    @Column(name = "symtomName", nullable = false, columnDefinition = "NVARCHAR2(15)")
    private String symtomName;

    @Column(name = "componentName", nullable = false, columnDefinition = "NVARCHAR2(15)")
    private String componentName;

    @Column(name = "componentSideEffects", columnDefinition = "NVARCHAR2(50)")
    private String componentSideEffects;

    @OneToMany(mappedBy = "detail_view")
    private List<Review> reviews;

    @OneToMany(mappedBy = "detail_view")
    private List<Finds> finds;
}