#include <iostream>
#include <memory>
#include "../include/models/Faculty.hpp"
#include "../include/models/StudyGroup.hpp"
#include "../include/models/Student.hpp"
#include "../include/models/Teacher.hpp"
#include "../include/models/Discipline.hpp"
#include "../include/core/TaskCreator.hpp"
#include "../include/models/GradeRecord.hpp"
#include "../include/models/Gradebook.hpp"
#include "../include/models/AcademicSession.hpp"
#include "../include/models/ScholarshipOrder.hpp"
#include "../include/core/Exceptions.hpp" 

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian"); 

    cout << " Система ВУЗа (Оценки, Стипендии и Исключения) \n\n";

    try {
        Faculty itFaculty("ФИВТ", nullptr);
        StudyGroup groupPRO("ПРО-329", 3, &itFaculty);

        Student s1(1, "Иван Иванов", "ivan", "1", "ZB-1", &groupPRO);
        Student s2(2, "Мария Смирнова", "maria", "2", "ZB-2", &groupPRO);
        Student s3(3, "Петр Петров", "petr", "3", "ZB-3", &groupPRO);
        
        Teacher prof(99, "Сергей Сергеевич", "serg", "admin", "ИТ");
        Discipline oop("ООП", 144, 4);

        unique_ptr<TaskCreator> labCreator = make_unique<LabWorkCreator>();
        unique_ptr<TaskCreator> examCreator = make_unique<ExamCreator>();
        
        unique_ptr<Task> labOOP = labCreator->create("Лабораторная №1", 5, "5");
        unique_ptr<Task> examOOP = examCreator->create("Экзамен ООП", 5, "15.06");

        AcademicSession summerSession("2023/2024", "Летняя");
        ScholarshipOrder order("104-СТ");
        
        summerSession.attachObserver(&order); 

        Gradebook gbLab(&oop, &groupPRO, "10.05");
        GradeRecord l1 = prof.gradeStudent(&s1, labOOP.get(), 2, "10.05"); 
        GradeRecord l2 = prof.gradeStudent(&s2, labOOP.get(), 5, "10.05"); 
        GradeRecord l3 = prof.gradeStudent(&s3, labOOP.get(), 3, "10.05"); 
        gbLab.addGrade(&l1); gbLab.addGrade(&l2); gbLab.addGrade(&l3);

        Gradebook gbExam(&oop, &groupPRO, "15.06");
        GradeRecord e1 = prof.gradeStudent(&s1, examOOP.get(), 5, "15.06");
        GradeRecord e2 = prof.gradeStudent(&s2, examOOP.get(), 4, "15.06"); 
        gbExam.addGrade(&e1); gbExam.addGrade(&e2);

        cout << "\n[!] Попытка поставить Петру 10 баллов...\n";
        GradeRecord e3 = prof.gradeStudent(&s3, examOOP.get(), 10, "15.06"); 
        

        gbExam.addGrade(&e3);

        summerSession.addGradebook(&gbLab);
        summerSession.addGradebook(&gbExam);
        summerSession.closeSession();
        order.printOrder();

    } 
    catch (const UniversityException& ex) {
        cerr << "\n[ОШИБКА ВУЗА]: " << ex.what() << "\n";
    }
    catch (const std::exception& ex) {
        cerr << "\n[СИСТЕМНАЯ ОШИБКА]: " << ex.what() << "\n";
    }

    return 0;
}