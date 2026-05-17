#include "../../include/models/Teacher.hpp"
#include "../../include/models/Student.hpp"
#include "../../include/models/Task.hpp"
#include "../../include/models/Discipline.hpp" 
#include "../../include/core/Exceptions.hpp"
#include <iostream>

Teacher::Teacher(int id, std::string name, std::string login, std::string pass, std::string dep)
    : User(id, name, login, pass), department(dep) {}

void Teacher::printRole() const {
    std::cout << "[Преподаватель] " << getName() << ", Кафедра: " << department << "\n";
    std::cout << "Ведет дисциплины:\n";
    for (const auto* d : disciplines) {
        std::cout << " - " << d->getName() << "\n";
    }
}

void Teacher::addDiscipline(Discipline* d) {
    if (d != nullptr) {
        disciplines.push_back(d);
    }
}

const std::vector<Discipline*>& Teacher::getDisciplines() const {
    return disciplines;
}

GradeRecord Teacher::gradeStudent(Student* student, Task* task, int score, std::string date) const {
    if (student == nullptr || task == nullptr) {
        throw NullEntityError("Студент или Задание");
    }
    if (score < 0 || score > task->getMaxScore()) {
        throw InvalidScoreError(score, task->getMaxScore());
    }

    std::cout << "Преподаватель " << getName() << " поставил " << score 
              << " баллов студенту " << student->getName() << "\n";
              
    return GradeRecord(student, task, score, date);
}