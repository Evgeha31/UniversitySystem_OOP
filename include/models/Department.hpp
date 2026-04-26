#pragma once
#include <string>
#include <vector>

class Teacher;
class Faculty; 

class Department {
private:
    std::string name;
    std::string headOfDepartment;
    Faculty* faculty; 
    std::vector<Teacher*> teachers;

public:
    Department(std::string name, std::string head, Faculty* fac);
    
    std::string getName() const;
    Faculty* getFaculty() const;
    void addTeacher(Teacher* teacher);
};