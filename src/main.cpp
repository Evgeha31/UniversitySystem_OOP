#include <iostream>
#include "../include/models/Institute.hpp"
#include "../include/models/Faculty.hpp"
#include "../include/models/Department.hpp"
#include "../include/models/StudyGroup.hpp"
#include "../include/models/Student.hpp"
#include "../include/models/Discipline.hpp"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian"); 

    cout << "Система Учета Успеваемости \n\n";

    Institute polytech("Политехнический Институт");
    Faculty itFaculty("ФИВТ", &polytech);

     Department csDept("Кафедра Программной Инженерии", "Проф. Иванов", &itFaculty);
    Discipline oop("Объектно-ориентированное программирование", 144, 4);

    StudyGroup groupPRO("ПРО-329", 3, &itFaculty);

    Student s1(1, "Иван Иванов", "ivan", "123", "ZB-001", &groupPRO);
    Student s2(2, "Мария Смирнова", "maria", "456", "ZB-002", &groupPRO);
    Student s3(3, "Петр Петров", "petr", "789", "ZB-003", &groupPRO);

    s1.printRole();
    cout << "\n";


    groupPRO.printGroupList();

    return 0;
}