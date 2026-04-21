#pragma once
#include <string>
#include "Faculty.hpp"

class StudyGroup {
private:
    std::string name;
    Faculty* faculty; 

public:
    StudyGroup(std::string name, Faculty* fac);
    std::string getName() const;
    Faculty* getFaculty() const;
};