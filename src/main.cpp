#include <iostream>
#include <vector>
#include "../include/core/TaskCreator.hpp"
#include "../include/models/Institute.hpp"
#include "../include/models/Faculty.hpp"
#include "../include/models/StudyGroup.hpp"
#include "../include/models/Student.hpp"
#include "../include/models/Teacher.hpp"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian"); 

    cout << "Система Учета Успеваемости ВУЗа \n\n";

    Institute polytech("Иснтитут информационных технологий и управляющих систем");
    Faculty itFaculty("Факультет программной инженерии и компьютерной техники", &polytech);
    StudyGroup groupPRO("ПВ-241", &itFaculty);

    Student student1(1, "Игнат Иванюк", "ivan.stud", "pass123", "ZB-10293", &groupPRO);
    Teacher teacher1(2, "Адрей Хлопов", "petr.prof", "qwert", "Высшая математика");

    student1.printRole();
    cout << "\n";
    teacher1.printRole();

    cout << "\nГенерация заданий (Паттерн Фабричный метод)\n";

    vector<unique_ptr<Task>> tasks;
    unique_ptr<TaskCreator> labCreator = make_unique<LabWorkCreator>();
    unique_ptr<TaskCreator> examCreator = make_unique<ExamCreator>();

    tasks.push_back(labCreator->create("ООП в C++", 10, "5"));
    tasks.push_back(examCreator->create("Алгебра", 100, "25.05.2026"));
        
    for (const auto& task : tasks) {
        task->printInfo();
    }

    return 0;
}