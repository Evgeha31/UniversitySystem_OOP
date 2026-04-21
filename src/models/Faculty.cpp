#include "../../include/models/Faculty.hpp"

Faculty::Faculty(std::string name, Institute* inst) : name(name), institute(inst) {}

std::string Faculty::getName() const {
    return name;
}

Institute* Faculty::getInstitute() const {
    return institute;
}