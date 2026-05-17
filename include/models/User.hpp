#pragma once
#include <string>

class User {
private:
    int id;
    std::string fullName;
    std::string login;
    std::string password;

public:
    User(int id, std::string name, std::string login, std::string pass)
        : id(id), fullName(name), login(login), password(pass) {}
    
    virtual ~User() = default;

    std::string getName() const { return fullName; }
    int getId() const { return id; }
    std::string getLogin() const { return login; }
    
    bool checkPassword(const std::string& pass) const {
        return password == pass;
    }
    
    virtual bool isTeacher() const = 0; 

    virtual void printRole() const = 0; 
};