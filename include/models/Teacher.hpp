#pragma once
#include "User.hpp"
#include <string>

class Teacher : public User {
private:
    std::string department;

public:
    Teacher(int id, std::string name, std::string login, std::string pass, std::string dep);

    void printRole() const override;
};