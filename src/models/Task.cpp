#include "../../include/models/Task.hpp"
#include <iostream>

using namespace std;

Task::Task(string t, int max) : title(t), maxScore(max) {}

LabWork::LabWork(string t, int max, int variant) : Task(t, max), variantNumber(variant) {}

void LabWork::printInfo() const {
    cout << "[Лабораторная] " << getTitle() << ", Вариант: " << variantNumber 
         << " (Макс. балл: " << getMaxScore() << ")" << endl;
}

Exam::Exam(string t, int max, string date) : Task(t, max), examDate(date) {}

void Exam::printInfo() const {
    cout << "[Экзамен] " << getTitle() << ", Дата: " << examDate 
         << " (Макс. балл: " << getMaxScore() << ")" << endl;
}

Credit::Credit(string t, int max, bool isDiff) : Task(t, max), isDifferentiated(isDiff) {}

void Credit::printInfo() const {
    string diffStr = isDifferentiated ? "Дифференцированный" : "Обычный (Зачет/Незачет)";
    cout << "[Зачет] " << getTitle() << " (" << diffStr << "), "
         << " (Макс. балл: " << getMaxScore() << ")" << endl;
}


RGZ::RGZ(string t, int max, string rgzTopic) : Task(t, max), topic(rgzTopic) {}

void RGZ::printInfo() const {
    cout << "[РГЗ] " << getTitle() << ", Тема: " << topic 
         << " (Макс. балл: " << getMaxScore() << ")" << endl;
}


CourseProject::CourseProject(string t, int max, string advisor) : Task(t, max), advisorName(advisor) {}

void CourseProject::printInfo() const {
    cout << "[Курсовой проект] " << getTitle() << ", Руководитель: " << advisorName 
         << " (Макс. балл: " << getMaxScore() << ")" << endl;
}