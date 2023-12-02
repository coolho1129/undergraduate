package com.knu.Team8Database.repository;

import com.knu.Team8Database.entity.Medicine;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;

import java.util.List;

public interface MedicineRepository extends JpaRepository<Medicine, Integer> {
    @Query("select m.name from Medicine m")
    List<String> findMedicine();

}
