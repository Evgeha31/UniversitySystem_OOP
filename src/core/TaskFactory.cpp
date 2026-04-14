#include "../../include/core/TaskFactory.hpp"
#include <stdexcept>

std::unique_ptr<Task> TaskFactory::createTask(
    const std::string& type, 
    const std::string& title, 
    int maxScore, 
    const std::string& extraParam) 
{
    if (type == "LabWork"){
        int variant = std::stoi(extraParam);
      return std::make_unique<LabWork>(title, maxScore, variant);
    } 
    else if (type == "Exam") {
        return std::make_unique<Exam>(title, maxScore, extraParam);
    } 
    else if (type == "Credit") {
        bool isDiff = (extraParam == "true" || extraParam == "1");
        return std::make_unique<Credit>(title, maxScore, isDiff);
    } 
    else if (type == "RGZ") {
        return std::make_unique<RGZ>(title, maxScore, extraParam);
    } 
    else if (type == "CourseProject") {
        return std::make_unique<CourseProject>(title, maxScore, extraParam);
    } 
    else {
        throw std::invalid_argument("Неизвестный тип задания: " + type);
    }
}