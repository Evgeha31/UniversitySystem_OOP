#pragma once
#include <string>
#include <vector>

class Discipline;
class StudyGroup;
class GradeRecord;

class Gradebook {
private:
    Discipline* discipline;
    StudyGroup* group;
    std::vector<GradeRecord*> records;
    std::string creationDate;

public:
    Gradebook(Discipline* discipline, StudyGroup* group, std::string date);
    
    void addGrade(GradeRecord* record);
    double calculateAverageScore() const;
    void printGradebook() const;
    Discipline* getDiscipline() const; 

    const std::vector<GradeRecord*>& getRecords() const;
    
    void clearRecords(); 
};