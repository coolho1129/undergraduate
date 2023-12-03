//package com.knu.Team8Database.repository;
//
//import com.knu.Team8Database.entity.Finds;
//import org.springframework.data.jpa.repository.JpaRepository;
//import org.springframework.data.jpa.repository.Query;
//import org.springframework.stereotype.Repository;
//
//import java.util.List;
//@Repository
//public interface FindsRepository extends JpaRepository<Finds, String> {
//    @Query("SELECT COUNT(*) AS find_count, D.medicineId, D.medicineName "+
//            "FROM Finds F " +
//            "JOIN Detail_view D ON F.detail_view = D.medicineId "+
//            "GROUP BY D.medicineId, D.medicineName "+
//            "ORDER BY find_count DESC " +
//            "FETCH FIRST 5 ROWS ONLY"
//            )
//    List<Finds> findByTop5();
//
//
//
//}
