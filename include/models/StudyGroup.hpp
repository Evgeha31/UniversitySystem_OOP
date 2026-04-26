#pragma once
#include <string>
#include <vector>

class Faculty; 
class Student; 

class StudyGroup {
private:
    std::string name;
    int course; 
    Faculty* faculty; 
    std::vector<Student*> students;

public:
    StudyGroup(std::string name, int course, Faculty* fac);
    std::string getName() const;
    Faculty* getFaculty() const;
    
    void addStudent(Student* student);
    void printGroupList() const; 
};