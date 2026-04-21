#include <iostream>
#include <vector>
// Заменяем старый инклуд на новый
#include "../include/core/TaskCreator.hpp" 
#include "../include/models/Student.hpp"
#include "../include/models/Teacher.hpp"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian"); 

    cout << "=== Система Учета Успеваемости ВУЗа ===\n\n";

    Student student1(1, "Иван Иванов", "ivan.stud", "pass123", "ZB-10293");
    Teacher teacher1(2, "Петр Петров", "petr.prof", "qwert", "Высшая математика");

    student1.printRole();
    teacher1.printRole();

    cout << "\n=== Генерация заданий (Истинный Паттерн Фабричный метод) ===\n";

    vector<unique_ptr<Task>> tasks;

    // Создаем конкретные фабрики
    unique_ptr<TaskCreator> labCreator = make_unique<LabWorkCreator>();
    unique_ptr<TaskCreator> examCreator = make_unique<ExamCreator>();
    unique_ptr<TaskCreator> courseCreator = make_unique<CourseProjectCreator>();

    // Фабрики генерируют объекты
    tasks.push_back(labCreator->create("ООП в C++", 10, "5"));
    tasks.push_back(examCreator->create("Алгебра", 100, "25.05.2024"));
    tasks.push_back(courseCreator->create("БД ВУЗа", 100, "Доц. Смирнов"));
        
    for (const auto& task : tasks) {
        task->printInfo();
    }

    return 0;
}