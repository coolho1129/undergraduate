package com.knu.Team8Database.repository;

import com.knu.Team8Database.entity.Medicine;
import org.springframework.data.jpa.repository.JpaRepository;

public interface MedicineRepository extends JpaRepository<Medicine, Long> {
}
