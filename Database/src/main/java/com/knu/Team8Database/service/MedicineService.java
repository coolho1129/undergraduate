package com.knu.Team8Database.service;

import com.knu.Team8Database.dto.Detail_viewDTO;
import com.knu.Team8Database.dto.MedicineReq;
import com.knu.Team8Database.entity.Detail_view;
import com.knu.Team8Database.repository.MedicineRepository;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.util.*;

@Service
@RequiredArgsConstructor
public class MedicineService {

    private final MedicineRepository medicineRepository;

    @Transactional(readOnly = true)
    public Detail_view findByMedicineId(String medicineId) {
        return medicineRepository.findByMedicineId(medicineId);
    }

    @Transactional(readOnly = true)
    public Map<String, Object> findDetailByMedicineId(String medicineId) {
        List<Detail_viewDTO> medicineList = medicineRepository.find_detail(medicineId);

        Map<String, Object> medicine = new HashMap<>();
        String medicineName = medicineList.get(0).getMedicineName();
        String capacity = medicineList.get(0).getMedicineCapacity();
        String price = medicineList.get(0).getMedicinePrice() + "원";
        String manufactureDate = medicineList.get(0).getMedicineManufactureDate();
        String companyName = medicineList.get(0).getCompanyName();
        String companyPhoneNumber = medicineList.get(0).getCompanyPhoneNumber();
        String companyWebsite = medicineList.get(0).getCompanyWebsite();

        Set<String> symptoms = new HashSet<>();
        Set<String> fields = new HashSet<>();
        Set<String> components = new HashSet<>();
        Set<String> sideEffects = new HashSet<>();

        for (Detail_viewDTO item : medicineList) {
            // value값이 List인거 -> symptom, field, component, sideEffect
            if (item.getSymtomName() != null)
                symptoms.add(item.getSymtomName());
            if (item.getSymtomField() != null)
                fields.add(item.getSymtomField());
            if (item.getComponentName() != null)
                components.add(item.getComponentName());
            if (item.getComponentSideEffects() != null)
                sideEffects.add(item.getComponentSideEffects());
        }

        List<String> uniqueSymptoms = new Vector<>(symptoms);
        List<String> uniqueFields = new Vector<>(fields);
        List<String> uniqueComponents = new Vector<>(components);
        List<String> uniqueSideEffects = new Vector<>(sideEffects);

        medicine.put("medicineId", medicineId);
        medicine.put("medicineName", medicineName);
        medicine.put("capacity", capacity);
        medicine.put("price", price);
        medicine.put("manufactureDate", manufactureDate);
        medicine.put("companyName", companyName);
        medicine.put("companyPhoneNumber", companyPhoneNumber);
        medicine.put("companyWebsite", companyWebsite);
        medicine.put("symptoms", uniqueSymptoms);
        medicine.put("fields", uniqueFields);
        medicine.put("components", uniqueComponents);
        medicine.put("sideEffects", uniqueSideEffects);

        return medicine;
    }

    @Transactional(readOnly = true)
    public List<Detail_viewDTO> findAllByItems(MedicineReq items) {
        if (items.getPrice().equals("")) items.setPrice("0");
        if (items.getField() == null) items.setField("");

        List<Detail_viewDTO> medicineList = medicineRepository.find_simple(
                items.getMedicine(),items.getComponent(),items.getSymptom(),
                items.getCompany(),Integer.parseInt(items.getPrice()), items.getField());

        System.out.println(medicineList);

        return medicineList;
    }
}
