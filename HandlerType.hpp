#ifndef HANDLERTYPE_HPP
#define HANDLERTYPE_HPP

#include <fstream>
#include "SpecType.hpp"

// HandlerType API
class HandlerType {
    private:
        std::string chem;
        std::string spec;
    public:
        HandlerType(std::string &chemName, SpecType type);
        std::ifstream getFileObj();
};

#endif