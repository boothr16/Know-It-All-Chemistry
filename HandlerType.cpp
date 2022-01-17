#include "HandlerType.hpp"

// HandlerType Implementation
HandlerType::HandlerType(std::string &chemName, SpecType type) {
    chemName[0] = toupper(chemName[0]);
    if (chemName.length() > 1) {
        for (int i = 1; i < chemName.length(); i++)
            chemName[i] = tolower(chemName[i]);
    }
    chem = chemName;
    spec = type.getType();
}

std::ifstream HandlerType::getFileObj() {
    std::string filePath = "./Samples/";
    filePath += (spec + "/");
    filePath += (chem + ".txt");
    return std::ifstream(filePath);
}