#include "../../include/models/Faculty.hpp"
#include "../../include/models/Institute.hpp"

Faculty::Faculty(std::string name, Institute* inst) : name(name), institute(inst) {}

std::string Faculty::getName() const { return name; }
Institute* Faculty::getInstitute() const { return institute; }

void Faculty::addDepartment(Department* dept) {
    departments.push_back(dept);
}