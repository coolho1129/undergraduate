package com.knu.Team8Database.entity;

import jakarta.persistence.*;
import java.util.Date;
import java.util.List;

@Entity
@Table(name = "component")
public class Component {
    @Id
    @Column(name = "component_id", nullable = false, length = 5)
    private String componentId;

    @Column(name = "name", nullable = false,columnDefinition = "NVARCHAR2(15)" )
    private String name;

    @Column(name = "side_effects", columnDefinition = "NVARCHAR2(50)")
    private String sideEffects;

    @OneToMany(mappedBy = "component")
    private List<Includes> includes;

}