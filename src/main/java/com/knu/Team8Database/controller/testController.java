package com.knu.Team8Database.controller;

import com.knu.Team8Database.dto.Detail_viewDTO;
import com.knu.Team8Database.repository.MedicineRepository;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;

import java.util.*;

@Controller
@RequiredArgsConstructor
public class testController {

    private final MedicineRepository medicineRepository;

    @GetMapping("/search")
    public String simple(Model model) {
        List<Detail_viewDTO> medicineList = medicineRepository.find_simple("패튼정","","","",0, "");
        Map<String,Map<String, Object>> itemMap = new HashMap<>();
        if (medicineList == null) System.out.println("빈 리스트임.");
        else {
            for(int i = 0; i< medicineList.size(); i++) {
                Detail_viewDTO medicines = medicineList.get(i);
                String medicineId = medicines.getMedicineId();
                String medicineName =  medicines.getMedicineName();
                String medicineCapacity = medicines.getMedicineCapacity();
                String symtomName = medicines.getSymtomName();
                String comapnyName = medicines.getCompanyName();
                if(itemMap.containsKey(medicineId)){
                    Map<String, Object> innerMap = itemMap.get(medicineId);
                    ((List<String>) innerMap.get("symtoms")).add(symtomName);
                }
                else{
                    Map<String, Object> innerMap = new HashMap<>();
                    List<String> symtoms = new Vector();
                    symtoms.add(symtomName);
                    innerMap.put("symtoms", symtoms);
                    innerMap.put("medicineName", medicineName);
                    innerMap.put("medicineCapacity", medicineCapacity);
                    innerMap.put("companyName", comapnyName);
                    itemMap.put(medicineId, innerMap);
                }
            }
        }
//        for (Map.Entry<String, Map<String, Object>> entry : itemMap.entrySet()) {
//            String medicineId = entry.getKey();
//            Map<String, Object> innerMap = entry.getValue();
//            List<String> symtoms = (List<String>) innerMap.get("symtoms");
//            String medicineName = (String) innerMap.get("medicineName");
//            String medicineCapacity = (String) innerMap.get("medicineCapacity");
//            String companyName = (String) innerMap.get("companyName");
//            System.out.println(medicineId + symtoms + medicineName + medicineCapacity + companyName);
//        }
        model.addAttribute("responseData", itemMap);
        return "index";
    }
}
