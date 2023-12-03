package com.knu.Team8Database.controller;

import ch.qos.logback.core.model.Model;
import com.knu.Team8Database.entity.Detail_view;
import com.knu.Team8Database.repository.MedicineRepository;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;

import java.util.List;

import static org.hibernate.sql.InFragment.NULL;

@Controller
@RequiredArgsConstructor
public class testController {

    private final MedicineRepository medicineRepository;

    @GetMapping("/search")
    public String simple(Model model) {
        List<Detail_view> medicineList = medicineRepository.find_simple("NULL");

        Detail_view medicines = medicineList.get(0);
        System.out.println(medicines.getMedicineId());
        return "index";
    }
}
