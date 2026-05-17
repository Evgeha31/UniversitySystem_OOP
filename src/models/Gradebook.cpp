#include "../../include/models/Gradebook.hpp"
#include "../../include/models/Discipline.hpp"
#include "../../include/models/StudyGroup.hpp"
#include "../../include/models/GradeRecord.hpp"
#include "../../include/models/Student.hpp"
#include "../../include/models/Task.hpp"
#include "../../include/core/Exceptions.hpp"
#include <iostream>

Gradebook::Gradebook(Discipline* discipline, StudyGroup* group, std::string date)
    : discipline(discipline), group(group), creationDate(date) {}

void Gradebook::addGrade(GradeRecord* record) {
    if (record == nullptr) {
        throw NullEntityError("GradeRecord");
    }
    records.push_back(record);
}

double Gradebook::calculateAverageScore() const {
    if (records.empty()) return 0.0;
    double sum = 0;
    for (const auto* rec : records) {
        sum += rec->getScore();
    }
    return sum / records.size();
}

void Gradebook::printGradebook() const {
    std::cout << "\nВЕДОМОСТЬ\n";
    std::cout << "Дисциплина: " << discipline->getName() << "\n";
    std::cout << "Группа: " << group->getName() << "\n";
    std::cout << "Средний балл группы: " << calculateAverageScore() << "\n";
    std::cout << "Оценки\n";
    
    for (const auto* rec : records) {
        std::cout << rec->getStudent()->getName() << " -> Балл: " << rec->getScore() 
                  << " (Макс: " << rec->getTask()->getMaxScore() << ")\n";
    }
}

Discipline* Gradebook::getDiscipline() const {
    return discipline;
}

const std::vector<GradeRecord*>& Gradebook::getRecords() const {
    return records;
}

void Gradebook::clearRecords() {
    for (auto* rec : records) {
        delete rec; 
    }
    records.clear();
}