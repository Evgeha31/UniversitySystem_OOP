#include "../../include/database/FileDB.hpp"
#include "../../include/models/Task.hpp"
#include "../../include/models/GradeRecord.hpp"
#include "../../include/models/Student.hpp"
#include "../../include/core/UniversityApp.hpp"
#include <fstream>
#include <sstream>

using namespace std;

void FileDB::saveTask(const string& type, Task* task, const string& param) {
    ofstream file("tasks.txt", ios::app); 
    if (file.is_open()) {
        file << type << "|" << task->getTitle() << "|" << task->getMaxScore() << "|" << param << "\n";
        file.close();
    }
}

void FileDB::saveGrade(GradeRecord* grade, const string& disciplineName) {
    ofstream file("grades.txt", ios::app);
    if (file.is_open()) {
        file << grade->getStudent()->getLogin() << "|" 
             << grade->getTask()->getTitle() << "|" 
             << grade->getScore() << "|" 
             << grade->getDate() << "|" 
             << disciplineName << "\n"; 
        file.close();
    }
}

void FileDB::loadTasks(UniversityApp* app) {
    ifstream file("tasks.txt");
    if (!file.is_open()) return;
    string line;
    while (getline(file, line)) {
        stringstream ss(line); string type, title, maxScoreStr, param;
        getline(ss, type, '|'); getline(ss, title, '|'); getline(ss, maxScoreStr, '|'); getline(ss, param, '|');
        if (type == "1") app->addTask(app->getLabCreator()->create(title, stoi(maxScoreStr), param));
        else if (type == "2") app->addTask(app->getExamCreator()->create(title, stoi(maxScoreStr), param));
    }
    file.close();
}

void FileDB::loadGrades(UniversityApp* app) {
    ifstream file("grades.txt");
    if (!file.is_open()) return;
    string line;
    while (getline(file, line)) {
        stringstream ss(line); string login, taskTitle, scoreStr, date, discName;
        getline(ss, login, '|'); getline(ss, taskTitle, '|'); 
        getline(ss, scoreStr, '|'); getline(ss, date, '|'); 
        getline(ss, discName, '|'); 

        Student* student = app->findStudentByLogin(login);
        Task* task = app->findTaskByTitle(taskTitle);
        if (student && task) {
            GradeRecord* rec = new GradeRecord(student, task, stoi(scoreStr), date);
            app->addLoadedGrade(rec, discName); 
        }
    }
    file.close();
}


void FileDB::clearDB() {
    ofstream t("tasks.txt", ios::trunc); t.close();
    ofstream g("grades.txt", ios::trunc); g.close();
    ofstream s("signatures.txt", ios::trunc); s.close(); 
}

void FileDB::saveSignature(int teacherId) {
    std::set<int> existing = loadSignatures();
    existing.insert(teacherId);
    ofstream file("signatures.txt", ios::trunc);
    if (file.is_open()) {
        for (int id : existing) {
            file << id << "\n";
        }
        file.close();
    }
}

std::set<int> FileDB::loadSignatures() {
    std::set<int> sigs;
    ifstream file("signatures.txt");
    if (!file.is_open()) return sigs;

    string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            sigs.insert(stoi(line));
        }
    }
    file.close();
    return sigs;
}