#pragma once
#include <string>


class Task {
private:
    std::string title;
    int maxScore;

public:
    Task(std::string t, int max);
    virtual ~Task() {}
    virtual void printInfo() const = 0;

    std::string getTitle() const {return title; }
    int getMaxScore() const {return maxScore; }
};

class LabWork : public Task {
private:
    int variantNumber;
public:
    LabWork(std::string t, int max, int variant);
    void printInfo() const override;
};

class Exam : public Task {
private:
    std::string examDate;
public:
    Exam(std::string t, int max, std::string date);
    void printInfo() const override;
};

class Credit : public Task {
private:
    bool isDifferentiated; 
public:
    Credit(std::string t, int max, bool isDiff);
    void printInfo() const override;
};


class RGZ : public Task {
private:
    std::string topic; 
public:
    RGZ(std::string t, int max, std::string rgzTopic);
    void printInfo() const override;
};


class CourseProject : public Task {
private:
    std::string advisorName; 
public:
    CourseProject(std::string t, int max, std::string advisor);
    void printInfo() const override;
};
