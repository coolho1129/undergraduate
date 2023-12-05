package com.knu.Team8Database.dto;

import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

import java.util.Date;

@Getter
@Setter
@NoArgsConstructor
public class UserReq {
    private String userId;
    private String name;
    private Date birth;
    private String password;
    private char gender;
}
