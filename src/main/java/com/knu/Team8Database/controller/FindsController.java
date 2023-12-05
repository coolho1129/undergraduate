package com.knu.Team8Database.controller;

import com.knu.Team8Database.dto.FindsDTO;
import com.knu.Team8Database.entity.Users;
import com.knu.Team8Database.repository.FindsRepository;
import jakarta.servlet.http.HttpSession;
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
    public String showRanking(Model model, HttpSession session){
        if (session.getAttribute("loginUser") != null) {
            Users loginUser = (Users) session.getAttribute("loginUser");
            model.addAttribute("loginUser", loginUser.getUsersId());
        }

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

        // HashMap을 정렬하기 위해 List로 변환합니다.
        List<Map.Entry<String, Map<String, Object>>> findsList = new ArrayList<>(findsMap.entrySet());

        // Comparator를 사용하여 findCount를 기준으로 내림차순으로 정렬합니다.
        findsList.sort((entry1, entry2) -> {
            Integer findCount1 = Integer.parseInt(entry1.getValue().get("findCount").toString());
            Integer findCount2 = Integer.parseInt(entry2.getValue().get("findCount").toString());
            return findCount2.compareTo(findCount1);
        });

        model.addAttribute("findsList", findsList);
        return "retrieve_ranking";
    }
}