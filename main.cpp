#include <iostream>
#include <fstream>
#include "SpecType.hpp"

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
        return 1;
    }
}