#pragma once
#include <string>
#include <vector>
#include "../core/IObserver.hpp"

class Gradebook;

class AcademicSession {
private:
    std::string year;
    std::string type; 
    bool isClosed;
    
    std::vector<Gradebook*> gradebooks; 
    std::vector<IObserver*> observers;  

public:
    AcademicSession(std::string year, std::string type);
    
    void addGradebook(Gradebook* gb);
    const std::vector<Gradebook*>& getGradebooks() const;
    
    void attachObserver(IObserver* observer);
    void notifyObservers();
    void closeSession();
};