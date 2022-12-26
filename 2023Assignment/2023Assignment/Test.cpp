#include "Mountains.h"

#include <iostream>
#include <string>
#include <vector>

// Declare the ranges variable as extern
extern std::map<std::string, std::vector<std::string>> ranges;

int main()
{
    // Read the mountain names from the input files
    std::vector<std::string> filenames = {"alps.txt", "pyrenees.txt", "carpathians.txt", "icelandic_highlands.txt"};
    Mountains mountains(filenames);

    // Print the ranges data structure
    for (const auto& [range, mountains] : ranges) {
        std::cout << range << ":" << std::endl;
        for (const auto& mountain : mountains) {
            std::cout << " - " << mountain << std::endl;
        }
    }

    return 0;
}