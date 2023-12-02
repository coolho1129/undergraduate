package com.knu.Team8Database.controller;

import com.knu.Team8Database.repository.MedicineRepository;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;

@Controller
@RequiredArgsConstructor
public class testController {

    private final MedicineRepository medicineRepository;

    @GetMapping("/")
    public String hello() {
        System.out.println(medicineRepository.findById(83787));
        return "index";
    }
}
