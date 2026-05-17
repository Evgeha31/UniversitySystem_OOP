#pragma once
#include "User.hpp"
#include <string>

class StudyGroup;

enum class StudentStatus { STUDYING, EXPELLED, ACADEMIC_LEAVE };

class Student : public User {
private:
    std::string recordBookNumber;
    StudyGroup* group;
    StudentStatus status; 

public:
    Student(int id, std::string name, std::string login, std::string pass, std::string rbNum, StudyGroup* grp);

    void printRole() const override;
    std::string getStatusString() const; 

    bool isTeacher() const override { return false; }
};