#ifndef SPECTYPE_HPP
#define SPECTYPE_HPP

#include <string>
#include <set>

class SpecType {
    private:
        std::string type;
        const std::set<std::string> SPEC_TYPES = {"UV", "MS"};
    public:
        SpecType(std::string &spec);
        bool isValid();
        std::string getType();
};

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

#endif