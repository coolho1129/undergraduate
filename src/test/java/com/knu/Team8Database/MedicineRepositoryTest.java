package com.knu.Team8Database;
import com.knu.Team8Database.entity.Detail_view;
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
        List<Detail_view> medicineList = medicineRepository.findAll();

        // then
        Detail_view medicines = medicineList.get(0);

        System.out.println(medicines);
    }}