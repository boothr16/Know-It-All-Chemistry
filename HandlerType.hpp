#ifndef HANDLERTYPE_HPP
#define HANDLERTYPE_HPP

#include <string>
#include <fstream>

class HandlerType {
    private:
        std::string chem;
        std::string spec;
    public:
        HandlerType(std::string chemName, std::string specType);
        std::ifstream getFileObj();
};

HandlerType::HandlerType(std::string chemName, std::string specType) {
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