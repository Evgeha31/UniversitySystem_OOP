#pragma once
#include "User.hpp"
#include "StudyGroup.hpp" 
#include <string>

class Student : public User {
private:
    std::string recordBookNumber;
    StudyGroup* group; 

public:
    Student(int id, std::string name, std::string login, std::string pass, std::string rbNum, StudyGroup* grp);

    void printRole() const override;
};