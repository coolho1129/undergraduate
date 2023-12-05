package com.knu.Team8Database.controller;

import com.knu.Team8Database.entity.Users;
import jakarta.servlet.http.HttpSession;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;

@Controller
public class HomeController {
    @GetMapping("/main")
    public String main(Model model, HttpSession session) {
        if (session.getAttribute("loginUser") != null) {
            Users loginUser = (Users) session.getAttribute("loginUser");
            model.addAttribute("loginUser", loginUser.getUsersId());
        }
        return "main";
    }

    @GetMapping("/member-info")
    public String member() {
        return "member_info";
    }
}
