package com.knu.Team8Database.controller;

import com.knu.Team8Database.dto.UserReq;
import com.knu.Team8Database.entity.Users;
import com.knu.Team8Database.repository.UserRepository;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpSession;
import lombok.RequiredArgsConstructor;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.validation.BindingResult;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;

@Controller
@RequiredArgsConstructor
public class UserController {
    @Autowired
    private HttpSession httpSession;

    private final UserRepository userRepository;

    @GetMapping("/login")
    public String loginPage(HttpSession session) {
        session.removeAttribute("loginUser");
        return "login";
    }

    @PostMapping("/login")
    public String login(String userId, String password,
                        HttpServletRequest request) {

        Users loginUser = userRepository.findByUsersId(userId);
        if (loginUser == null) {
            return "login";
        }
        else if (loginUser.getUsersPassword().equals(password)) {
            HttpSession session = request.getSession();
            session.setAttribute("loginUser", loginUser);

            return "redirect:/main";
        }
        else return "login";
    }

    @GetMapping("/logout")
    public String logout(HttpSession session) {
        session.removeAttribute("loginUser");
        return "redirect:/main";
    }

    @GetMapping("/signin")
    public String signinPage() {
        return "signin";
    }

    @PostMapping("/signin")
    public String signin(UserReq userReq, Model model) {
        Users user = Users.builder()
                .usersId(userReq.getUserId())
                .usersName(userReq.getName())
                .usersBirth(userReq.getBirth())
                .usersPassword(userReq.getPassword())
                .usersGender(userReq.getGender()).build();

        userRepository.save(user);
        return "login";
    }
}
