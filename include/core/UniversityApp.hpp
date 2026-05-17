#pragma once
#include <vector>
#include <memory>
#include <string>

#include "../models/Institute.hpp"
#include "../models/Faculty.hpp"
#include "../models/StudyGroup.hpp"
#include "../models/Student.hpp"
#include "../models/Teacher.hpp"
#include "../models/Discipline.hpp"
#include "../models/GradeRecord.hpp"
#include "../models/Gradebook.hpp"
#include "../models/AcademicSession.hpp"
#include "../models/ScholarshipOrder.hpp"
#include "../core/TaskCreator.hpp"

class UniversityApp {
private:
    Faculty itFaculty;
    StudyGroup groupPRO;
    Discipline oop, math, physics, db;
    
    Student s1, s2, s3, s4, s5;
    
    Teacher profOOP, profMath, profPhysics;

    std::vector<User*> allUsers;
    std::vector<Student*> groupStudents;
    std::vector<std::unique_ptr<Task>> systemTasks;

    Gradebook gbOOP, gbMath, gbPhysics, gbDB;
    
    AcademicSession summerSession;
    ScholarshipOrder order;

    std::unique_ptr<TaskCreator> labCreator;
    std::unique_ptr<TaskCreator> examCreator;

    bool isRunning;

public:
    UniversityApp();
    void run();

    TaskCreator* getLabCreator() { return labCreator.get(); }
    TaskCreator* getExamCreator() { return examCreator.get(); }
    void addTask(std::unique_ptr<Task> t) { systemTasks.push_back(std::move(t)); }
    Student* findStudentByLogin(const std::string& login);
    Task* findTaskByTitle(const std::string& title);
    
    // Обновленный метод
    void addLoadedGrade(GradeRecord* rec, const std::string& discName);

private:
    void syncWithDatabase();
    void handleLogin();
    User* authenticateUser(const std::string& login, const std::string& pass);
    void studentMenu(Student* student);
    void showStudentGrades(Student* student);
    void teacherMenu(Teacher* teacher);
    void handleTaskCreation();
    void handleGrading(Teacher* teacher);
    void handleSessionClose(Teacher* teacher);
};