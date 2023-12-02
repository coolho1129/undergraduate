package com.knu.Team8Database;
import com.knu.Team8Database.entity.Medicine;
import com.knu.Team8Database.repository.MedicineRepository;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import java.util.List;

import static org.assertj.core.api.AssertionsForClassTypes.assertThat;

@SpringBootTest
public class MedicineRepositoryTest {
    @Autowired
    private MedicineRepository medicineRepository;
    @Test
    public void testCustomQuery() {

        // when
        List<String> medicineList = medicineRepository.findMedicine();

        // then
        String medicines = medicineList.get(0);
        // assertThat(medicines .getName());

        System.out.println(medicineList);
    }}