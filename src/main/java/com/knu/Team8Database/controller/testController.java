package com.knu.Team8Database.controller;

import ch.qos.logback.core.model.Model;
import com.knu.Team8Database.dto.responseDTO;
import com.knu.Team8Database.entity.Detail_view;
import com.knu.Team8Database.repository.MedicineRepository;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;

import java.util.List;

@Controller
@RequiredArgsConstructor
public class testController {

    private final MedicineRepository medicineRepository;

    @GetMapping("/")
    public String simple(Model model) {
        List<responseDTO> medicineList = medicineRepository.find_simple("패튼정");
        if (medicineList == null) System.out.println("빈 리스트임.");
        else {
            responseDTO medicines = medicineList.get(0);
            System.out.println(medicines.getMedicineId());
        }
        return "index";
    }
}
