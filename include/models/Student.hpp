#pragma once
#include "User.hpp"
#include <string>

class Student : public User {
private:
    std::string recordBookNumber;

public:
    Student(int id, std::string name, std::string login, std::string pass, std::string rbNum);

    void printRole() const override;
};