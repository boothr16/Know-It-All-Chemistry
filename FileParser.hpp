#ifndef FILEPARSER_HPP
#define FILEPARSER_HPP

#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
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

// TODO: IMPLEMENT LOGIC FOR SNR CALCULATION USING PRIORITY QUEUE
void FileParser::parseUV(std::ifstream &inFile) {
    double maxWav = -1, maxAbs = -1;
    std::priority_queue<double, std::vector<double>, std::greater<double>> pq; // for estimating noise
    std::string line;
    while (getline(inFile, line)) {
        if (line.length() < 2)
            break;
        int spacePos = line.find(' ');
        double wav = stod(line.substr(0, spacePos));
        double abs = stod(line.substr(spacePos+1));
        if (abs > maxAbs) {
            maxWav = wav;
            maxAbs = abs;
        }
        pq.push(abs);
    }
    inFile.close();
    // Use smallest 10 Abs values to estimate noise
    const int NOISE_SAMPLE = 10;
    double mean = 0;
    std::vector<double> noiseVec;
    for (int i = 0; i < NOISE_SAMPLE; i++) {
        noiseVec.push_back(pq.top());
        mean += pq.top();
        pq.pop();
    }
    mean /= NOISE_SAMPLE;
    double stdDev = 0;
    for (int i = 0; i < NOISE_SAMPLE; i++) {
        stdDev += std::pow((noiseVec[i] - mean), 2);
    }
    stdDev = std::sqrt(stdDev);
    double SNR = maxAbs / stdDev;
    std::cout << "Substance absorbs most strongly at a wavelength of " << maxWav << " nm.";
    std::cout << "ABS_MAX = " << maxAbs << ", SNR = " << SNR << std::endl;
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
    double percentAbun = (1 / totalIntensity) * 100;
    std::cout << "The most abundant fragment ion recorded has a mass/charge";
    std::cout << " ratio of " << mzRatio << " and a percent abundance";
    std::cout << " of " << percentAbun << "%\n";
}



#endif