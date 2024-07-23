package com.knu.Team8Database.dto;

import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

@Getter
@Setter
@NoArgsConstructor
public class MedicineReq {
    private String medicine;
    private String company;
    private String field;
    private String component;
    private String symptom;
    private String price;
}
