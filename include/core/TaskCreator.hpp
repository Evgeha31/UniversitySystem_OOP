#pragma once
#include <memory>
#include <string>
#include "../models/Task.hpp"

class TaskCreator {
public:
    virtual ~TaskCreator() = default;
    
    virtual std::unique_ptr<Task> create(const std::string& title, int maxScore, const std::string& param) const = 0;
};

class LabWorkCreator : public TaskCreator {
public:
    std::unique_ptr<Task> create(const std::string& title, int maxScore, const std::string& param) const override;
};

class ExamCreator : public TaskCreator {
public:
    std::unique_ptr<Task> create(const std::string& title, int maxScore, const std::string& param) const override;
};

class CreditCreator : public TaskCreator {
public:
    std::unique_ptr<Task> create(const std::string& title, int maxScore, const std::string& param) const override;
};

class CourseProjectCreator : public TaskCreator {
public:
    std::unique_ptr<Task> create(const std::string& title, int maxScore, const std::string& param) const override;
};

class RGZCreator : public TaskCreator {
public:
    std::unique_ptr<Task> create(const std::string& title, int maxScore, const std::string& param) const override;
};