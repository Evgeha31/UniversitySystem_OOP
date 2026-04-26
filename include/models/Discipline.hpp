#pragma once
#include <string>

class Discipline {
private:
    std::string name;
    int hours;
    int semester;
public:
    Discipline(std::string name, int hoursm, int semester);
    std::string getName()const;
    void changeHours(int newHours);
};