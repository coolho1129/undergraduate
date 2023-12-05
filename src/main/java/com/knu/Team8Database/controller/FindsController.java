package com.knu.Team8Database.controller;

import com.knu.Team8Database.dto.FindsDTO;
import com.knu.Team8Database.repository.FindsRepository;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;

import java.util.*;

@Controller
@RequiredArgsConstructor
public class FindsController {
    private final FindsRepository findsRepository;

    @GetMapping("/finds")
    public String showRanking(Model model){
        List<FindsDTO> findsDTOList = findsRepository.findByTop5();
        Map<String, Map<String, Object>> findsMap = new HashMap<>();

        for (int i = 0; i < 5; i++) {
            FindsDTO finds = findsDTOList.get(i);
            String findCount = finds.getFindCount();
            String medicineId = finds.getMedicineId();
            String medicineName = finds.getMedicineName();

            Map<String, Object> innerMap = new HashMap<>();
            innerMap.put("findCount", findCount);
            innerMap.put("medicineName", medicineName);
            findsMap.put(medicineId, innerMap);
        }
        model.addAttribute("findsMap", findsMap);
        return "retrieve_ranking";
    }
}