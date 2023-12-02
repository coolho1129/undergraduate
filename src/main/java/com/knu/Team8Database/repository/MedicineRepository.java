package com.knu.Team8Database.repository;

import com.knu.Team8Database.entity.Detail_view;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;

import java.util.List;

public interface MedicineRepository extends JpaRepository<Detail_view, String> {
}
