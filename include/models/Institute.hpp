#pragma once
#include <string>

class Institute {
private:
    std::string name;

public:
    Institute(std::string name);
    std::string getName() const;
};