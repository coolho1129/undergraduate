package com.knu.Team8Database.controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;

@Controller
public class HomeController {
    @GetMapping("/main")
    public String main() {
        return "main";
    }
}
