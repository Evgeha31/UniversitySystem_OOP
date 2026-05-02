#pragma once
#include <exception>
#include <string>

class UniversityException : public std::exception {
private: 
    std::string message;
public:
    explicit UniversityException(const std::string& msg) : message(msg) {}
    
    const char* what() const noexcept override { 
        return message.c_str(); 
    }
};

class InvalidScoreError : public UniversityException {
public:
    InvalidScoreError(int score, int maxScore) 
        : UniversityException("Сбой оценки: балл " + std::to_string(score) + 
                              " недопустим. Максимум: " + std::to_string(maxScore)) {}
};

class NullEntityError : public UniversityException {
public:
    NullEntityError(const std::string& entityName) 
        : UniversityException("Сбой данных: Объект '" + entityName + "' не существует (nullptr)!") {}
};

class InvalidDataFormatError : public UniversityException {
public:
    InvalidDataFormatError(const std::string& detail) 
        : UniversityException("Сбой формата: " + detail) {}
};