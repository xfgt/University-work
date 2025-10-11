//
// Created by LOCAL_ADMIN on 11.10.2025 г..
//

#include <set>
#include <string>
#include <iostream>

struct Student {
    std::string name;
    double grade;


    bool operator<(const Student& other) const {
        if (grade != other.grade) return grade > other.grade;
        return name < other.name;
    }
};

int main() {
    std::set<Student> students;


    students.insert({"Ana", 3.80});
    students.insert({"Boris", 5.10});
    students.insert({"Ana", 4.75});


    for (const auto& s : students) {
        std::cout << s.name << " " << s.grade << "\n";
    }
}