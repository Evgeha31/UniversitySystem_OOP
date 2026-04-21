#include "../../include/models/Institute.hpp"

Institute::Institute(std::string name) : name(name) {}

std::string Institute::getName() const {
    return name;
}