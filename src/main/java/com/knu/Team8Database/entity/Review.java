package com.knu.Team8Database.entity;

import jakarta.persistence.*;
import lombok.Getter;
import lombok.Setter;

import java.util.Date;

@Getter
@Setter
@Entity
@Table(name = "review")
public class Review {
    @Id
    @Column(name = "review_id", nullable = false, length = 6)
    private String reviewId;

    @ManyToOne
    @JoinColumn(name = "user_id", nullable = false)
    private User user;

    @ManyToOne
    @JoinColumn(name = "medicineId", nullable = false)
    private Detail_view detail_view;

    @ManyToOne
    @JoinColumn(name = "admin_id", nullable = false)
    private Admin admin;

    @Column(name = "rating", nullable = false)
    private Double rating;

    @Column(name = "review_date")
    @Temporal(TemporalType.DATE)
    private Date reviewDate;

    @Column(name = "comments", columnDefinition = "NVARCHAR2(50)")
    private String comments;

}