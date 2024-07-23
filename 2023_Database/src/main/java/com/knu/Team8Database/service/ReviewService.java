package com.knu.Team8Database.service;

import com.knu.Team8Database.dto.ReviewDTO;
import com.knu.Team8Database.entity.Admin;
import com.knu.Team8Database.entity.Detail_view;
import com.knu.Team8Database.entity.Review;
import com.knu.Team8Database.entity.Users;
import com.knu.Team8Database.repository.AdminRepository;
import com.knu.Team8Database.repository.ReviewRepository;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Isolation;
import org.springframework.transaction.annotation.Transactional;

import java.util.Collections;
import java.util.Date;
import java.util.List;
import java.util.Random;

@Service
@RequiredArgsConstructor
public class ReviewService {

    private final ReviewRepository reviewRepository;
    private final AdminRepository adminRepository;

    @Transactional(readOnly = true)
    public List<ReviewDTO> findAllByMedicineId(String medicineId) {
        return reviewRepository.findMedicineReview(medicineId);
    }

    @Transactional(readOnly = true)
    public List<ReviewDTO> findAllReview() {
        return reviewRepository.findAllReview();
    }

    @Transactional(isolation = Isolation.READ_COMMITTED)
    public void saveReview(Users user, Detail_view medicine, Double rating, String comments) {
        String generateReviewId;
        String newReviewId;

        do {
            generateReviewId = generateRandomId();
            newReviewId = reviewRepository.findReviewID(generateReviewId);
        } while (newReviewId == null);

        List<String> adminList = adminRepository.getAdminId();
        Collections.shuffle(adminList);
        Admin admin = adminRepository.findByAdminId(adminList.get(0));

        Review review = Review.builder()
                .reviewId(newReviewId)
                .usersId(user)
                .medicineId(medicine)
                .adminId(admin)
                .reviewRating(rating)
                .reviewDate(new Date())
                .reviewComments(comments)
                .build();

        reviewRepository.save(review);
    }

    private String generateRandomId() {
        int randomLength = new Random().nextInt(6) + 1; // 1에서 6 사이의 랜덤한 길이
        StringBuilder randomId = new StringBuilder();

        for (int i = 0; i < randomLength; i++) {
            randomId.append(new Random().nextInt(10)); // 0에서 9 사이의 랜덤한 숫자
        }

        return randomId.toString();
    }
}
