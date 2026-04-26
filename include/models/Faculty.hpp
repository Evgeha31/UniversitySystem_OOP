#pragma once
#include <string>
#include <vector>

class Institute;
class Department; 

class Faculty {
private:
    std::string name;
    Institute* institute;
    std::vector<Department*> departments; 

public:
    Faculty(std::string name, Institute* inst);
    std::string getName() const;
    Institute* getInstitute() const;
    
    void addDepartment(Department* dept); 
};