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
    public String saveReview(String rating, String comments, String medicineId, Model model) {
        System.out.println(rating);
        System.out.println(comments);
        System.out.println(medicineId);

        return "redirect:/search?param=" + medicineId;
    }
}

