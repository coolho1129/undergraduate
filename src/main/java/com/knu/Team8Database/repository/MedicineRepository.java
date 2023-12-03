package com.knu.Team8Database.repository;

import com.knu.Team8Database.dto.responseDTO;
import com.knu.Team8Database.entity.Detail_view;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;
import org.springframework.data.repository.query.Param;
import org.springframework.stereotype.Repository;

import java.util.List;

@Repository
public interface MedicineRepository extends JpaRepository<Detail_view, String> {
//    @Query("SELECT D.medicineId, D.medicineName, D.medicineCapacity, D.medicinePrice, D.medicineManufactureDate," +
//            "D.companyName, D.companyPhoneNumber,D.companyWebsite,D.symtomName, D.symtomField," +
//            "D.componentName, D.componentSideEffects FROM Detail_view D")
//    List<Detail_view> find_detail();

    @Query("SELECT D.medicineId AS medicineId, D.medicineName AS medicineName, D.medicineCapacity AS medicineCapacity, D.symtomName AS symtomName, D.companyName AS companyName\n" +
            "FROM Detail_view D WHERE D.medicineName = :medicine_name")
    List<responseDTO> find_simple(@Param("medicine_name")String medicine_name);

    //List<Detail_view> findAllByMedicineName(String medicineName);
}
