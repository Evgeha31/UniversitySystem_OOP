#include "../../include/models/AcademicSession.hpp"
#include <iostream>

AcademicSession::AcademicSession(std::string year, std::string type)
    : year(year), type(type), isClosed(false) {}

void AcademicSession::addGradebook(Gradebook* gb) {
    gradebooks.push_back(gb);
}

const std::vector<Gradebook*>& AcademicSession::getGradebooks() const {
    return gradebooks;
}

void AcademicSession::attachObserver(IObserver* observer) {
    observers.push_back(observer);
}

void AcademicSession::notifyObservers() {
    for (auto* obs : observers) {
        obs->update(this); 
    }
}

void AcademicSession::closeSession() {
    isClosed = true;
    std::cout << "\n" << type << " сессия " << year << " официально ЗАКРЫТА!\n";
    std::cout << "Идет автоматическое формирование приказов...\n";
    notifyObservers(); 
}