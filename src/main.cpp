#include <iostream>
#include <vector>
#include "../include/core/TaskFactory.hpp"
#include "../include/models/Student.hpp"
#include "../include/models/Teacher.hpp"

using namespace std;

int main(){
    setlocale(LC_ALL, "Russian");
    cout << "Система учета успеваемвости вуза \n";

    Student student1(1, "Игнат Иванюк", "ignat.stud", "11102006", "10293");
    Teacher teacher1(2, "Андрей Хлопов", "Andrey.prepod", "qwerty", "Высшая математика");

    student1.printRole();
    teacher1.printRole();

        vector<unique_ptr<Task>> tasks;

    try {
        tasks.push_back(TaskFactory::createTask("LabWork", "ООП в C++", 10, "5"));
        tasks.push_back(TaskFactory::createTask("Exam", "Системное моделирование", 100, "05.06.2026"));
        tasks.push_back(TaskFactory::createTask("CourseProject", "БД ВУЗа", 100, "Доц. Смирнов"));
        tasks.push_back(TaskFactory::createTask("Credit", "Физкультура", 100, "0"));
        
        for (const auto& task : tasks) {
            task->printInfo();
        }
    } 
    catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }

    return 0;
}
