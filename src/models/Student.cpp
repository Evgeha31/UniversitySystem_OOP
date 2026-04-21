#include "../../include/models/Student.hpp"
#include <iostream>

Student::Student(int id, std::string name, std::string login, std::string pass, std::string rbNum, StudyGroup* grp)
    : User(id, name, login, pass), recordBookNumber(rbNum), group(grp) {}

void Student::printRole() const {
    std::cout << "[Студент] " << getName() << ", Зачетка: " << recordBookNumber << "\n";
    
    if (group != nullptr) {
        std::cout << "  -> Группа: " << group->getName() << "\n"
                  << "  -> Факультет: " << group->getFaculty()->getName() << "\n"
                  << "  -> Институт: " << group->getFaculty()->getInstitute()->getName() << "\n";
    }
}