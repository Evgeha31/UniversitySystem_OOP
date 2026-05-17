#pragma once
#include <string>
#include <set> // <-- НОВЫЙ ИНКЛУД

class Task;
class GradeRecord;
class UniversityApp;

class FileDB {
public:
    static void saveTask(const std::string& type, Task* task, const std::string& param);
    static void saveGrade(GradeRecord* grade, const std::string& disciplineName);
    static void loadTasks(UniversityApp* app);
    static void loadGrades(UniversityApp* app);
    static void clearDB();

    static void saveSignature(int teacherId);
    static std::set<int> loadSignatures();
};