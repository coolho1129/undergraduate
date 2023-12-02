package com.knu.Team8Database.repository;

import com.knu.Team8Database.entity.Detail_view;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;

import java.util.List;

public interface MedicineRepository extends JpaRepository<Detail_view, String> {
    @Query("select D.medicineId, D.medicineName, D.medicineCapacity, D.medicinePrice, D.medicineManufactureDate," +
            "D.companyName, D.companyPhoneNumber,D.companyWebsite,D.symtomName, D.symtomField," +
            "D.componentName, D.componentSideEffects FROM Detail_view D")
    List <Detail_view> find_detail();

}
