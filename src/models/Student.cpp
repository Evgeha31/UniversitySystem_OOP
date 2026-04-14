#include "../../include/models/Student.hpp"
#include <iostream>

Student::Student(int id,std::string name, std::string login, std::string pass, std::string rbNum)
    : User(id,name, login,pass), recordBookNumber(rbNum) {}

void Student::printRole() const {
    std::cout << "[Студент]" << getName() << ", Зачетка: " << recordBookNumber << "\n";
}