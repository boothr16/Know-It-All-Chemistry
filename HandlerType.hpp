#ifndef HANDLERTYPE_HPP
#define HANDLERTYPE_HPP

#include <string>
#include <fstream>
#include "SpecType.hpp"

class HandlerType {
    private:
        std::string chem;
        std::string spec;
    public:
        HandlerType(std::string chemName, SpecType type);
        std::ifstream getFileObj();
};

HandlerType::HandlerType(std::string chemName, SpecType type) {
    chem = chemName;
    spec = specType;
}

std::ifstream HandlerType::getFileObj() {
    std::string filePath = "./Samples/";
    filePath += (spec + "/");
    filePath += (chem + ".txt");
    return std::ifstream(filePath);
}

#endif