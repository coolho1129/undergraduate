package com.knu.Team8Database.controller;

import com.knu.Team8Database.dto.Detail_viewDTO;
import com.knu.Team8Database.dto.MedicineReq;
import com.knu.Team8Database.repository.MedicineRepository;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Vector;

@Controller
@RequiredArgsConstructor
public class MedicineController {

    private final MedicineRepository medicineRepository;

    @PostMapping("/search")
    public String searchMedicine(MedicineReq medicineReq, Model model) {
        if (medicineReq.getPrice().equals("")) medicineReq.setPrice("0");

        List<Detail_viewDTO> medicineList = medicineRepository.find_simple(
                medicineReq.getMedicine(),medicineReq.getComponent(),medicineReq.getSymptom(),
                medicineReq.getCompany(),Integer.parseInt(medicineReq.getPrice()), medicineReq.getField());

        Map<String,Map<String, Object>> itemMap = new HashMap<>();
        for(int i = 0; i< medicineList.size(); i++) {
            Detail_viewDTO medicines = medicineList.get(i);

            String medicineId = medicines.getMedicineId();
            String medicineName =  medicines.getMedicineName();
            String medicineCapacity = medicines.getMedicineCapacity();
            String symptomName = medicines.getSymtomName();
            String companyName = medicines.getCompanyName();

            if(itemMap.containsKey(medicineId)){
                Map<String, Object> innerMap = itemMap.get(medicineId);
                ((List<String>) innerMap.get("symptoms")).add(symptomName);
            }
            else{
                Map<String, Object> innerMap = new HashMap<>();
                List<String> symptoms = new Vector();
                symptoms.add(symptomName);
                innerMap.put("symptoms", symptoms);
                innerMap.put("medicineName", medicineName);
                innerMap.put("medicineCapacity", medicineCapacity);
                innerMap.put("companyName", companyName);
                itemMap.put(medicineId, innerMap);
            }
        }

        model.addAttribute("responseData", itemMap);
        return "retrieve_result";
    }
}
