#include "../../include/models/StudyGroup.hpp"
#include "../../include/models/Faculty.hpp"
#include "../../include/models/Student.hpp"
#include <iostream>

StudyGroup::StudyGroup(std::string name, int course, Faculty* fac) 
    : name(name), course(course), faculty(fac) {}

std::string StudyGroup::getName() const { return name; }
Faculty* StudyGroup::getFaculty() const { return faculty; }

void StudyGroup::addStudent(Student* student) {
    students.push_back(student);
}

void StudyGroup::printGroupList() const {
    std::cout << " Список группы " << name << " (" << course << " курс)\n";
    for (const auto& student : students) {
        std::cout << "- " << student->getName() << "\n";
    }
}