#pragma once
#include <string>
#include <vector>
#include "../core/IObserver.hpp"

class Student;

class ScholarshipOrder : public IObserver {
private:
    std::string orderNumber;
    std::vector<Student*> scholars; 

public:
    ScholarshipOrder(std::string number);
    
    void update(AcademicSession* session) override; 
    void printOrder() const;
};