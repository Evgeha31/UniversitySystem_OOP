#pragma once
#include <memory>
#include <string>
#include "../models/Task.hpp"

class TaskFactory{
public:
    static std::unique_ptr<Task> createTask(
        const std::string& type,
        const std::string& title,
        int maxScore,
        const std::string&extraParam
    );
};