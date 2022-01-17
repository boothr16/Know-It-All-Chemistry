#include "SpecType.hpp"

// SpecType Implementation
SpecType::SpecType(std::string &spec) {
    for (int i = 0; i < spec.length(); i++) {
        spec[i] = toupper(spec[i]);
    }
    type = spec;
}

bool SpecType::isValid() {
    if (type.length() < 2)
        return false;
    if (SPEC_TYPES.find(type) == SPEC_TYPES.end())
        return false;
    return true;
}

std::string SpecType::getType() {
    return type;
}