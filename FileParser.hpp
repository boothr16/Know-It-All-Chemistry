#ifndef FILEPARSER_HPP
#define FILEPARSER_HPP

#include <fstream>
#include "SpecType.hpp"

class FileParser {
    public:
        FileParser(std::ifstream inFile, SpecType spec);
        void parseUV(std::ifstream inFile);
        void parseMS(std::ifstream inFile);
};

FileParser::FileParser(std::ifstream inFile, SpecType spec) {
    if (spec.getType() == "UV")
        parseUV(inFile);
    if (spec.getType() == "MS")
        parseMS(inFile);
}

#endif