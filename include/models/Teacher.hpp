#pragma once
#include "User.hpp"
#include "GradeRecord.hpp" 
#include <string>

class Student; 
class Task;

class Teacher : public User {
private:
    std::string department;

public:
    Teacher(int id, std::string name, std::string login, std::string pass, std::string dep);

    void printRole() const override;

    GradeRecord gradeStudent(Student* student, Task* task, int score, std::string date) const;
};