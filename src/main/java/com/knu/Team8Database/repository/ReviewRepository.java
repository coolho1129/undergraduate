package com.knu.Team8Database.repository;

import com.knu.Team8Database.entity.Review;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Modifying;
import org.springframework.data.jpa.repository.Query;
import org.springframework.data.repository.query.Param;
import org.springframework.stereotype.Repository;

import java.util.List;

//- 의약품 검색
//        - request: 의약품명, 성분명, 제조회사명, 효능효과, 가격, 진료분과
//        - response: medicine_name, capacity, symptom, company
//        - 아이디별 의약품 검색
//        - request: medicine_id
//        - response: 전부 다
//        - 리뷰 작성
//        - request: 의약품명, 사용자명, 별점, 코멘트
//        - 의약품별 리뷰 확인
//        - request: medicine id
//        - response: 사용자명, 별점, 코멘트

//        - 많이 찾은 제품
//        - response: find횟수, medicine_id, 의약품명

@Repository
public interface ReviewRepository extends JpaRepository<Review, String> {
    @Query("SELECT D.medicineName, U.name, R.rating, R.comments " +
            "FROM Review R, User U, Detail_view D"
    )
    List<Review> findAllReview();

    @Query("SELECT U.name, R.rating, R.comments " +
            "FROM Review R, User U, Detail_view D " +
            "WHERE (:medicine_id IS NULL OR D.medicineId = :medicine_id)"
    )
    List<Review> findMedicineReview(@Param("medicine_id") String medicine_id);

}