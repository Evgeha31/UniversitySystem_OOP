#pragma once
#include "User.hpp"
#include "GradeRecord.hpp"
#include <string>
#include <vector>

class Student;
class Task;
class Discipline;

class Teacher : public User {
private:
    std::string department;
    std::vector<Discipline*> disciplines;

public:
    Teacher(int id, std::string name, std::string login, std::string pass, std::string dep);

    void printRole() const override;
    
    bool isTeacher() const override { return true; }

    void addDiscipline(Discipline* d);
    const std::vector<Discipline*>& getDisciplines() const;

    GradeRecord gradeStudent(Student* student, Task* task, int score, std::string date) const;
};