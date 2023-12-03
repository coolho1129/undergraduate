package com.knu.Team8Database.repository;//package com.knu.Team8Database.repository;
//
//import com.knu.Team8Database.entity.Finds;
import com.knu.Team8Database.entity.Finds;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;
import org.springframework.stereotype.Repository;

import java.util.List;
@Repository
public interface FindsRepository extends JpaRepository<Finds, String> {
    @Query("SELECT COUNT(*) AS findCount, D.medicineId as medicineId, D.medicineName as medicineName " +
            "FROM Finds F " +
            "JOIN Detail_view D ON F.detail_view.medicineId = D.medicineId " +
            "GROUP BY D.medicineId, D.medicineName " +
            "ORDER BY findCount DESC " +
            "FETCH FIRST 5 ROWS ONLY"
    )
    List<Object[]> findByTop5();



}
