package com.knu.Team8Database.service;

import com.knu.Team8Database.dto.FindsDTO;
import com.knu.Team8Database.entity.Detail_view;
import com.knu.Team8Database.entity.Finds;
import com.knu.Team8Database.entity.Users;
import com.knu.Team8Database.repository.FindsRepository;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Isolation;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;

@Service
@RequiredArgsConstructor
public class FindsService {

    private final FindsRepository findsRepository;

    @Transactional(readOnly = true)
    public List<FindsDTO> findsRanking() {
        return findsRepository.findsRanking();
    }

    @Transactional(isolation = Isolation.READ_COMMITTED)
    public void findsMedicine(Detail_view medicine, Users user) {
        Finds finds = Finds.builder()
                .medicineId(medicine)
                .usersId(user)
                .build();
        findsRepository.save(finds);
    }
}
