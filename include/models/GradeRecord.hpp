#pragma once
#include <string>

class Student;
class Task;

class GradeRecord {
private:
    Student* student;
    Task* task;
    int score;
    std::string date;

public:
    GradeRecord(Student* student, Task* task, int score, std::string date);
    
    int getScore() const;
    void updateScore(int newScore);
    
    Student* getStudent() const;
    Task* getTask() const;
    std::string getDate() const;
};