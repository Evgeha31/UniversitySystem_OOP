#include "../../include/models/Student.hpp"
#include "../../include/models/StudyGroup.hpp"
#include "../../include/models/Faculty.hpp"
#include "../../include/models/Institute.hpp"
#include <iostream>

Student::Student(int id, std::string name, std::string login, std::string pass, std::string rbNum, StudyGroup* grp)
    : User(id, name, login, pass), recordBookNumber(rbNum), group(grp), status(StudentStatus::STUDYING) {
    
    if (group != nullptr) {
        group->addStudent(this);
    }
}

std::string Student::getStatusString() const {
    switch(status) {
        case StudentStatus::STUDYING: return "Учится";
        case StudentStatus::EXPELLED: return "Отчислен";
        case StudentStatus::ACADEMIC_LEAVE: return "В академе";
        default: return "Неизвестно";
    }
}

void Student::printRole() const {
    std::cout << "[Студент] " << getName() << ", Зачетка: " << recordBookNumber 
              << ", Статус: " << getStatusString() << "\n";
    
    if (group != nullptr) {
        std::cout << "  -> Группа: " << group->getName() << "\n";
    }
}