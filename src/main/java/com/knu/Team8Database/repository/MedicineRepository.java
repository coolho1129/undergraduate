package com.knu.Team8Database.repository;

import com.knu.Team8Database.dto.Detail_viewDTO;
import com.knu.Team8Database.entity.Detail_view;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;
import org.springframework.data.repository.query.Param;
import org.springframework.stereotype.Repository;

import java.util.List;

@Repository
public interface MedicineRepository extends JpaRepository<Detail_view, String> {

    @Query("SELECT D.medicineId, D.medicineName, D.medicineCapacity, D.symtomName, D.companyName " +
            "FROM Detail_view D WHERE (D.medicineName LIKE %:medicineName%) AND (D.symtomName LIKE %:symtomName%)" +
            " AND (D.companyName LIKE %:companyName%) AND (D.medicineCapacity LIKE %:medicineCapacity%)" +
            " AND (D.medicinePrice >= :medicinePrice) AND (D.symtomField LIKE %:symtomField %)")
    List<Detail_viewDTO> find_simple(@Param("medicineName")String medicineName, @Param("medicineCapacity")String medicineCapacity,
                                     @Param("symtomName")String symtomName,@Param("companyName")String companyName,
                                     @Param("medicinePrice")Integer medicinePrice, @Param("symtomField")String symtomField);

}

