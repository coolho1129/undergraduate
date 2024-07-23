package com.knu.Team8Database.controller;

import com.knu.Team8Database.dto.ReviewDTO;
import com.knu.Team8Database.entity.*;
import com.knu.Team8Database.repository.AdminRepository;
import com.knu.Team8Database.repository.MedicineRepository;
import com.knu.Team8Database.repository.ReviewRepository;
import com.knu.Team8Database.repository.UserRepository;
import com.knu.Team8Database.service.MedicineService;
import com.knu.Team8Database.service.ReviewService;
import jakarta.servlet.http.HttpSession;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;

import java.util.*;

@Controller
@RequiredArgsConstructor
public class ReviewController {
    private final ReviewService reviewService;
    private final MedicineService medicineService;

    @GetMapping("/review")
    public String showALLReview(@RequestParam(value="page", defaultValue = "1") int page,
                                Model model, HttpSession session) {
        if (session.getAttribute("loginUser") != null) {
            Users loginUser = (Users) session.getAttribute("loginUser");
            model.addAttribute("loginUser", loginUser.getUsersId());
        }

        List<ReviewDTO> reviewDTOList = reviewService.findAllReview();
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
    public String saveReview(Double rating, String comments, String medicineId,
                             Model model, HttpSession session) {
        if (session.getAttribute("loginUser") == null) {
            model.addAttribute("loginFail", "로그인 후 이용 가능합니다.");
            return "login";
        }

        Users loginUser = (Users) session.getAttribute("loginUser");
        Detail_view medicine = medicineService.findByMedicineId(medicineId);

        reviewService.saveReview(loginUser, medicine, rating, comments);
        return "redirect:/search?param=" + medicineId;
    }
}

