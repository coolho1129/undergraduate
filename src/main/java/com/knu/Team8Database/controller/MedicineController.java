package com.knu.Team8Database.controller;

import com.knu.Team8Database.dto.Detail_viewDTO;
import com.knu.Team8Database.dto.MedicineReq;
import com.knu.Team8Database.dto.ReviewDTO;
import com.knu.Team8Database.entity.Detail_view;
import com.knu.Team8Database.entity.Users;
import com.knu.Team8Database.service.FindsService;
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
public class MedicineController {

    private final MedicineService medicineService;
    private final ReviewService reviewService;
    private final FindsService findsService;

    @GetMapping("/search")
    public String searchDetail(@RequestParam("param") String medicineId,
                               Model model, HttpSession session) {
        if (session.getAttribute("loginUser") != null) {
            Users loginUser = (Users) session.getAttribute("loginUser");
            model.addAttribute("loginUser", loginUser.getUsersId());

            Detail_view medicine = medicineService.findByMedicineId(medicineId);
            findsService.findsMedicine(medicine, loginUser);
        }

        Map<String, Object> medicine = medicineService.findDetailByMedicineId(medicineId);
        model.addAttribute("responseData", medicine);

        List<ReviewDTO> reviewDTOList = reviewService.findAllByMedicineId(medicineId);
        List<Map<String, String>> reviewData = new Vector<>();

        for (ReviewDTO reviewDTO : reviewDTOList) {
            Map<String, String> review = new HashMap<>();

            review.put("UserName", reviewDTO.getUsersName());
            review.put("Rating", reviewDTO.getReviewRating());
            review.put("Comments", reviewDTO.getReviewComments());

            reviewData.add(review);
        }
        model.addAttribute("reviewData", reviewData);

        return "detail";
    }

    @PostMapping("/search")
    public String searchMedicine(MedicineReq medicineReq,
                                 Model model, HttpSession session) {
        if (session.getAttribute("loginUser") != null) {
            Users loginUser = (Users) session.getAttribute("loginUser");
            model.addAttribute("loginUser", loginUser.getUsersId());
        }

        List<Detail_viewDTO> medicineList = medicineService.findAllByItems(medicineReq);

        Map<String,Map<String, Object>> itemMap = new HashMap<>();
        for(int i = 0; i< medicineList.size(); i++) {
            Detail_viewDTO medicines = medicineList.get(i);

            String medicinesId = medicines.getMedicineId();
            String medicinesName =  medicines.getMedicineName();
            String medicinesCapacity = medicines.getMedicineCapacity();
            String symptomsName = medicines.getSymtomName();
            String companysName = medicines.getCompanyName();

            if(itemMap.containsKey(medicinesId)){
                Map<String, Object> innerMap = itemMap.get(medicinesId);
                ((Set<String>) innerMap.get("symptoms")).add(symptomsName);
            }
            else{
                Map<String, Object> innerMap = new HashMap<>();
                Set<String> symptoms = new HashSet();
                symptoms.add(symptomsName);
                innerMap.put("symptoms", symptoms);
                innerMap.put("medicineName", medicinesName);
                innerMap.put("medicineCapacity", medicinesCapacity);
                innerMap.put("companyName", companysName);
                itemMap.put(medicinesId, innerMap);
            }
        }

        model.addAttribute("responseData", itemMap);
        return "retrieve_result";
    }
}