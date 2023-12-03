package com.knu.Team8Database.controller;

import ch.qos.logback.core.model.Model;
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

    @GetMapping("/search")
    public String simple(Model model) {
        List<Detail_view> medicineList = medicineRepository.find_simple();
        System.out.println(medicineList.get(0).getMedicineId());
        return "index";
    }
}
