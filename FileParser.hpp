#ifndef FILEPARSER_HPP
#define FILEPARSER_HPP

#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include "SpecType.hpp"

// FileParser API
class FileParser {
    private:
        void parseUV(std::ifstream &inFile);
        void parseMS(std::ifstream &inFile);
    public:
        FileParser(std::ifstream &inFile, SpecType spec);
};

#endif