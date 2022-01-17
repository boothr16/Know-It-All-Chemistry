#include "SpecType.hpp"
#include "HandlerType.hpp"
#include "FileParser.hpp"

int main(int argc, char *argv[])
{
    if (argc != 3) {
        std::cout << "USAGE: ./kia <chemical name> <spectrum type>\n";
        return 1;
    }
    std::string spec = argv[2];
    SpecType typeIn(spec);
    if (!typeIn.isValid()) {
        std::cout << "Invalid spectrum type. Valid spectrum types: \n";
        return 2;
    }

    std::string chemIn = argv[1];
    HandlerType sampleInfo(chemIn, typeIn);
    std::ifstream inFile = sampleInfo.getFileObj();
    if (!inFile) {
        std::cout << "Requested information not available.\n";
        return 3;
    }
    FileParser(inFile, typeIn);
    return 0;
}