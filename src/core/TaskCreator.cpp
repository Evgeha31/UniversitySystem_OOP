#include "../../include/core/TaskCreator.hpp"
#include <stdexcept>

std::unique_ptr<Task> LabWorkCreator::create(const std::string& title, int maxScore, const std::string& param) const {
    int variant = std::stoi(param);
    return std::make_unique<LabWork>(title, maxScore, variant);
}

std::unique_ptr<Task> ExamCreator::create(const std::string& title, int maxScore, const std::string& param) const {
    return std::make_unique<Exam>(title, maxScore, param);
}

std::unique_ptr<Task> CreditCreator::create(const std::string& title, int maxScore, const std::string& param) const {
    bool isDiff = (param == "true" || param == "1");
    return std::make_unique<Credit>(title, maxScore, isDiff);
}

std::unique_ptr<Task> CourseProjectCreator::create(const std::string& title, int maxScore, const std::string& param) const {
    return std::make_unique<CourseProject>(title, maxScore, param);
}

std::unique_ptr<Task> RGZCreator::create(const std::string& title, int maxScore, const std::string& param) const {
    return std::make_unique<RGZ>(title, maxScore, param);
}