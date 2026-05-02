#include "../../include/models/ScholarshipOrder.hpp"
#include "../../include/models/AcademicSession.hpp"
#include "../../include/models/Gradebook.hpp"
#include "../../include/models/GradeRecord.hpp"
#include "../../include/models/Student.hpp"
#include "../../include/models/Task.hpp"
#include <iostream>
#include <map>

ScholarshipOrder::ScholarshipOrder(std::string number) : orderNumber(number) {}

void ScholarshipOrder::update(AcademicSession* session) {
    std::map<Student*, bool> studentStatus;

    for (auto* gb : session->getGradebooks()) {
        for (auto* rec : gb->getRecords()) {
            
            Student* currentStudent = rec->getStudent();
            int score = rec->getScore();
            Task* currentTask = rec->getTask();

            if (studentStatus.find(currentStudent) == studentStatus.end()) {
                studentStatus[currentStudent] = true;
            }

            if (currentTask->isFinal() && score < 4) {
                studentStatus[currentStudent] = false;
            }
        }
    }

    scholars.clear();
    for (const auto& pair : studentStatus) {
        if (pair.second == true) { 
            scholars.push_back(pair.first);
        }
    }
}

void ScholarshipOrder::printOrder() const {
    std::cout << "  ПРИКАЗ О НАЗНАЧЕНИИ СТИПЕНДИИ № " << orderNumber << "\n";
    if (scholars.empty()) {
        std::cout << "Нет студентов, претендующих на стипендию.\n";
    } else {
        for (const auto* s : scholars) {
            std::cout << " - " << s->getName() << "\n";
        }
    }
}