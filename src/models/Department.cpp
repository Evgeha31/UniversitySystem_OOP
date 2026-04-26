#include "../../include/models/Department.hpp"
#include "../../include/models/Faculty.hpp" 

Department::Department(std::string name, std::string head, Faculty* fac) 
    : name(name), headOfDepartment(head), faculty(fac) {
    
    if (faculty != nullptr) {
        faculty->addDepartment(this);
    }
}

std::string Department::getName() const { return name; }
Faculty* Department::getFaculty() const { return faculty; }

void Department::addTeacher(Teacher* teacher) {
    teachers.push_back(teacher);
}