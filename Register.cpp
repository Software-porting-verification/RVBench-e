#include "Register.h"
#include <unordered_set>

std::string Register::get_name() const {
    return name;
}

double Register::get_value() const {
    return value;
}

void Register::set_value(double value) {
    this->value = value;
}

