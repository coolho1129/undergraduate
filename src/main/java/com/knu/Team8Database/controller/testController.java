package com.knu.Team8Database.controller;

import com.knu.Team8Database.dto.Detail_viewDTO;
import com.knu.Team8Database.repository.MedicineRepository;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;

import java.util.*;

import static org.thymeleaf.util.StringUtils.length;

@Controller
@RequiredArgsConstructor
public class testController {


    private final MedicineRepository medicineRepository;

    @GetMapping("/search")
    public String simple(Model model) {
        List<Detail_viewDTO> medicineList = medicineRepository.find_simple("","","","",0, "");
        Map<String, String> itemMap = new HashMap<>();
        List <Map> result = new ArrayList<>();
        if (medicineList == null) System.out.println("빈 리스트임.");
        else {
            for(int i = 0; i<length(medicineList); i++) {
                Detail_viewDTO medicines = medicineList.get(i);
                itemMap.put("medicineId", medicines.getMedicineId());
                itemMap.put("medicineName", medicines.getMedicineName());
                itemMap.put("medicineCapacity",medicines.getMedicineCapacity());
                itemMap.put("symtomName", medicines.getSymtomName());
                itemMap.put("comapnyName", medicines.getCompanyName());
                result.add(itemMap);
            }
        }
        model.addAttribute("responseData",result);
        return "index";
    }
}
