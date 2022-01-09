#ifndef FILEPARSER_HPP
#define FILEPARSER_HPP

#include <fstream>
#include <iostream>
#include "SpecType.hpp"

class FileParser {
    private:
        void parseUV(std::ifstream &inFile);
        void parseMS(std::ifstream &inFile);
    public:
        FileParser(std::ifstream &inFile, SpecType spec);
};

FileParser::FileParser(std::ifstream &inFile, SpecType spec) {
    if (spec.getType() == "UV")
        parseUV(inFile);
    if (spec.getType() == "MS")
        parseMS(inFile);
}

void FileParser::parseUV(std::ifstream &inFile) {

}

void FileParser::parseMS(std::ifstream &inFile) {
    int mzRatio = -1;
    double totalIntensity = 0;
    int IN_DATA = 0;
    std::string line;
    while (getline(inFile, line)) {
        if (line[0] == '#' && IN_DATA == 0) {
            continue;
        }
        else if (line[0] == '#' && IN_DATA == 1) {
            break;
        }
        else {
            if (IN_DATA == 0)
                IN_DATA = 1;
            int spacePos = line.find(' ');
            double peakIntensity = stod(line.substr(spacePos+1));
            if (peakIntensity == 1) {
                int comPos = line.find(',');
                mzRatio = stoi(line.substr(0,comPos));
            }
            totalIntensity += peakIntensity;
        }
    }
    inFile.close();
    double percentAbun = (1 / (1 + totalIntensity)) * 100;
    std::cout << "The most common fragment ion formed has a mass/charge";
    std::cout << " ratio of " << mzRatio << " and a relative abundance";
    std::cout << " of " << percentAbun << "%\n";
}



#endif