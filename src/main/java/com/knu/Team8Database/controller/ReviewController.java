package com.knu.Team8Database.controller;

import com.knu.Team8Database.dto.ReviewDTO;
import com.knu.Team8Database.repository.ReviewRepository;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Vector;

@Controller
@RequiredArgsConstructor
public class ReviewController {
    private final ReviewRepository reviewRepository;

    @GetMapping("/review")
    public String showALLReview(Model model) {
        List<ReviewDTO> reviewDTOList = reviewRepository.findAllReview();
        List<Map<String, String>> reviewList = new Vector<>();
        for (ReviewDTO reviewDTO : reviewDTOList) {
            Map<String, String> review = new HashMap<>();
            review.put("medicineId", reviewDTO.getMedicineId());
            review.put("userName", reviewDTO.getUsersName());
            review.put("medicineName", reviewDTO.getMedicineName());
            review.put("rating", reviewDTO.getReviewRating());
            review.put("comments", reviewDTO.getReviewComments());

            reviewList.add(review);
         }

        model.addAttribute("reviewList", reviewList);
        return "review_list";
    }
}

