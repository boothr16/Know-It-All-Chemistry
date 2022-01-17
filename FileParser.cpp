#include "FileParser.hpp"

// FileParser Implementation
FileParser::FileParser(std::ifstream &inFile, SpecType spec) {
    if (spec.getType() == "UV")
        parseUV(inFile);
    if (spec.getType() == "MS")
        parseMS(inFile);
}

void FileParser::parseUV(std::ifstream &inFile) {
    double maxWav = -1, maxAbs = -1, sum = 0;
    std::vector<double> heights;
    std::string line;
    while (getline(inFile, line)) {
        if (line.length() < 2)
            break;
        int spacePos = line.find('\t');
        double wav = stod(line.substr(0, spacePos));
        double abs = stod(line.substr(spacePos+1));
        if (abs > maxAbs) {
            maxWav = wav;
            maxAbs = abs;
        }
        heights.push_back(abs);
        sum += abs;
    }
    inFile.close();
    double mean = sum / heights.size();
    double stdDev = 0;
    for (double i : heights)
        stdDev += std::pow((i - mean), 2);
    stdDev = std::sqrt(stdDev / heights.size());
    double SNR = mean / stdDev;
    std::cout << "Substance absorbs most strongly at a wavelength of " << maxWav << " nm.";
    std::cout << "\nABS_MAX = " << maxAbs << ", SNR = " << SNR << std::endl;
}

void FileParser::parseMS(std::ifstream &inFile) {
    // For identifying most abundant fragment ion and its percent abundance
    int maxMzRatio = -1;
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
                maxMzRatio = stoi(line.substr(0,comPos));
            }
            totalIntensity += peakIntensity;
        }
    }
    inFile.close();
    double percentAbun = (1 / totalIntensity) * 100;
    std::cout << "The most abundant fragment ion recorded has a mass/charge";
    std::cout << " ratio of " << maxMzRatio << " and a percent abundance";
    std::cout << " of " << percentAbun << "%\n";
}