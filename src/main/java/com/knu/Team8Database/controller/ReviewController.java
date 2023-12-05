package com.knu.Team8Database.controller;

import com.knu.Team8Database.dto.ReviewDTO;
import com.knu.Team8Database.entity.*;
import com.knu.Team8Database.repository.AdminRepository;
import com.knu.Team8Database.repository.MedicineRepository;
import com.knu.Team8Database.repository.ReviewRepository;
import com.knu.Team8Database.repository.UserRepository;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;

import java.util.*;

@Controller
@RequiredArgsConstructor
public class ReviewController {
    private final ReviewRepository reviewRepository;
    private final MedicineRepository medicineRepository;
    private final AdminRepository adminRepository;
    private final UserRepository userRepository;

    @GetMapping("/review")
    public String showALLReview(@RequestParam(value="page", defaultValue = "1") int page, Model model) {
        List<ReviewDTO> reviewDTOList = reviewRepository.findAllReview();
        List<Map<String, String>> reviewList = new Vector<>();
        for (int i = 0; i < 10; i++) {
            ReviewDTO reviewDTO = reviewDTOList.get(i + 10*(page-1));
            Map<String, String> review = new HashMap<>();
            review.put("medicineId", reviewDTO.getMedicineId());
            review.put("userName", reviewDTO.getUsersName());
            review.put("medicineName", reviewDTO.getMedicineName());
            review.put("rating", reviewDTO.getReviewRating());
            review.put("comments", reviewDTO.getReviewComments());
            review.put("date", reviewDTO.getReviewDate());

            reviewList.add(review);
        }

        model.addAttribute("currentPage", page);
        model.addAttribute("totalPages", reviewDTOList.size() / 10 + 1);
        model.addAttribute("reviewList", reviewList);
        return "review_list";
    }

    @PostMapping("/review")
    public String saveReview(
            Double rating, String comments, String medicineId, Model model
    ) {
        Users user = userRepository.findByUsersId("mXww86wy");
        Detail_view medicine = medicineRepository.findByMedicineId(medicineId);
        Admin admin = adminRepository.findByAdminId("xsiI32Xo");

        Review review = Review.builder()
                .reviewId("00000")
                .usersId(user)
                .medicineId(medicine)
                .adminId(admin)
                .reviewRating(rating)
                .reviewDate(new Date())
                .reviewComments(comments)
                .build();

        reviewRepository.save(review);
        return "redirect:/search?param=" + medicineId;
    }
}

