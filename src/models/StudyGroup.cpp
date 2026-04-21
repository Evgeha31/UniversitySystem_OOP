#include "../../include/models/StudyGroup.hpp"

StudyGroup::StudyGroup(std::string name, Faculty* fac) : name(name), faculty(fac) {}

std::string StudyGroup::getName() const {
    return name;
}

Faculty* StudyGroup::getFaculty() const {
    return faculty;
}