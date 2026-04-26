#include "../../include/models/Discipline.hpp"
#include <iostream>

Discipline::Discipline(std::string name, int hours, int semester) 
    : name(name), hours(hours), semester(semester) {}

std::string Discipline::getName() const { return name; }

void Discipline::changeHours(int newHours) {
    hours = newHours;
    std::cout << "Количество часов для '" << name << "' изменено на " << hours << "\n";
}