#include "../../include/models/Teacher.hpp"
#include <iostream>

Teacher::Teacher(int id, std::string name, std::string login, std::string pass, std::string dep)
    : User(id, name, login, pass), department(dep) {}

void Teacher::printRole() const {
    std::cout << "[Преподаватель] " << getName() << ", Кафедра: " << department << "\n";
}