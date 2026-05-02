#include "../../include/models/GradeRecord.hpp"
#include "../../include/models/Student.hpp"
#include "../../include/models/Task.hpp"

GradeRecord::GradeRecord(Student* student, Task* task, int score, std::string date)
    : student(student), task(task), score(score), date(date) {}

int GradeRecord::getScore() const { return score; }

void GradeRecord::updateScore(int newScore) { score = newScore; }

Student* GradeRecord::getStudent() const { return student; }
Task* GradeRecord::getTask() const { return task; }
std::string GradeRecord::getDate() const { return date; }