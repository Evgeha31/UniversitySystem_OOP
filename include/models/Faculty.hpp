#pragma once
#include <string>
#include "Institute.hpp"

class Faculty {
private:
    std::string name;
    Institute* institute; 

public:
    Faculty(std::string name, Institute* inst);
    std::string getName() const;
    Institute* getInstitute() const;
};