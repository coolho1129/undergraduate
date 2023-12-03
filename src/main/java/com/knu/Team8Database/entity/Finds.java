package com.knu.Team8Database.entity;

import jakarta.persistence.*;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.util.Objects;

@Getter
@Setter
@Entity
@Table(name = "finds")
@IdClass(Finds.FindsId.class)
public class Finds {

    @Id
    @ManyToOne
    @JoinColumn(name = "user_id", nullable = false)
    private User user;

    @Id
    @ManyToOne
    @JoinColumn(name = "medicineId", nullable = false)
    private Detail_view detail_view;

    // 기본 생성자, Getter, Setter 등 생략

    @Getter
    @Setter
    public static class FindsId implements Serializable {
        private User user;
        private Detail_view detail_view;

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            FindsId findsId = (FindsId) o;
            return Objects.equals(user, findsId.user) && Objects.equals(detail_view, findsId.detail_view);
        }

        @Override
        public int hashCode() {
            return Objects.hash(user, detail_view);
        }
    }
}
