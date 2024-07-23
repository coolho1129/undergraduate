package com.knu.Team8Database.service;

import com.knu.Team8Database.dto.UserReq;
import com.knu.Team8Database.entity.Users;
import com.knu.Team8Database.repository.UserRepository;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Isolation;
import org.springframework.transaction.annotation.Transactional;

@Service
@RequiredArgsConstructor
public class UserService {

    private final UserRepository userRepository;

    @Transactional(readOnly = true)
    public Users findByUsersId(String userId) {
        return userRepository.findByUsersId(userId);
    }

    @Transactional(isolation = Isolation.READ_COMMITTED)
    public void saveUser(UserReq userReq) {
        Users user = Users.builder()
                .usersId(userReq.getUserId())
                .usersName(userReq.getName())
                .usersBirth(userReq.getBirth())
                .usersPassword(userReq.getPassword())
                .usersGender(userReq.getGender()).build();

        userRepository.save(user);
    }
}
