#ifndef SPECTYPE_HPP
#define SPECTYPE_HPP

#include <string>
#include <set>

class SpecType {
    private:
        std::string type;
    public:
        SpecType(std::string &spec);
        bool isValid();
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
    const std::set<std::string> SPEC_TYPES = {"UV", "MS"};
    if (SPEC_TYPES.find(type) == SPEC_TYPES.end())
        return false;
    return true;
}

#endif