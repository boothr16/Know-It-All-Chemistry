#ifndef SPECTYPE_HPP
#define SPECTYPE_HPP

#include <string>
#include <set>

// SpecType API
class SpecType {
    private:
        std::string type;
        const std::set<std::string> SPEC_TYPES = {"UV", "MS"};
    public:
        SpecType(std::string &spec);
        bool isValid();
        std::string getType();
};

#endif