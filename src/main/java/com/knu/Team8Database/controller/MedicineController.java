package com.knu.Team8Database.controller;

import com.knu.Team8Database.dto.Detail_viewDTO;
import com.knu.Team8Database.dto.MedicineReq;
import com.knu.Team8Database.dto.ReviewDTO;
import com.knu.Team8Database.entity.Users;
import com.knu.Team8Database.repository.MedicineRepository;
import com.knu.Team8Database.repository.ReviewRepository;
import jakarta.servlet.http.HttpSession;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;

import java.util.*;

@Controller
@RequiredArgsConstructor
public class MedicineController {

    private final MedicineRepository medicineRepository;
    private final ReviewRepository reviewRepository;

    @GetMapping("/search")
    public String searchDetail(@RequestParam("param") String medicineId,
                               Model model, HttpSession session) {
        if (session.getAttribute("loginUser") != null) {
            Users loginUser = (Users) session.getAttribute("loginUser");
            model.addAttribute("loginUser", loginUser.getUsersId());
        }

        List<Detail_viewDTO> medicineDetail = medicineRepository.find_detail(medicineId);
        Map<String,Map<String, Object>> itemMap = new HashMap<>();

        for(int i = 0; i< medicineDetail.size(); i++) {
            Detail_viewDTO medicine = medicineDetail.get(i);

            String medicineName = medicine.getMedicineName();
            String medicineCapacity = medicine.getMedicineCapacity();
            String medicinePrice = medicine.getMedicinePrice();
            String medicineManufactureDate = medicine.getMedicineManufactureDate();
            String symptomName = medicine.getSymtomName();
            String symptomField = medicine.getSymtomField();
            String companyName = medicine.getCompanyName();
            String companyPhoneNumber = medicine.getCompanyPhoneNumber();
            String companyWebsite = medicine.getCompanyWebsite();
            String componentName = medicine.getComponentName();
            String componentSideEffect = medicine.getComponentSideEffects();

            if(itemMap.containsKey(medicineId)){
                Map<String, Object> innerMap = itemMap.get(medicineId);
                ((Set<String>) innerMap.get("symptoms")).add(symptomName);
                ((Set<String>) innerMap.get("symptomFields")).add(symptomField);
                ((Set<String>) innerMap.get("components")).add(componentName);
                ((Set<String>) innerMap.get("componentSideEffects")).add(componentSideEffect);
            }
            else{
                Map<String, Object> innerMap = new HashMap<>();
                Set<String> symptoms = new HashSet();
                Set<String> symptomFields = new HashSet();
                Set<String> components = new HashSet();
                Set<String> componentSideEffects = new HashSet();
                symptoms.add(symptomName);
                symptomFields.add(symptomField);
                components.add(componentName);
                componentSideEffects.add(componentSideEffect);

                innerMap.put("symptoms", symptoms);
                innerMap.put("symptomFields", symptomFields);
                innerMap.put("components", components);
                innerMap.put("componentSideEffects", componentSideEffects);
                innerMap.put("medicineName", medicineName);
                innerMap.put("medicineCapacity", medicineCapacity);
                innerMap.put("medicinePrice", medicinePrice);
                innerMap.put("medicineManufactureDate", medicineManufactureDate);
                innerMap.put("companyName", companyName);
                innerMap.put("companyPhoneNumber", companyPhoneNumber);
                innerMap.put("companyWebsite", companyWebsite);
                itemMap.put(medicineId, innerMap);
            }
        }
        model.addAttribute("responseData", itemMap);

        List<ReviewDTO> reviewDTOList = reviewRepository.findMedicineReview(medicineId);
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

        if (medicineReq.getPrice().equals("")) medicineReq.setPrice("0");

        List<Detail_viewDTO> medicineList = medicineRepository.find_simple(
                medicineReq.getMedicine(),medicineReq.getComponent(),medicineReq.getSymptom(),
                medicineReq.getCompany(),Integer.parseInt(medicineReq.getPrice()), medicineReq.getField());

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