// To implement the Mountains class, you can use a std::map where the keys are the mountain ranges and the values are std::vectors of mountain names in that range.

// Here is one way you can implement the Mountains class based on the requirements you provided:

#include "Mountains.h"
#include <algorithm>  // for std::find
#include <fstream>    // for std::ifstream
#include <map>        // for std::map
#include <random>     // for std::uniform_int_distribution
#include <string>     // for std::string
#include <vector>     // for std::vector

std::map<std::string, std::vector<std::string>> ranges;  // map of mountain ranges to mountain names

Mountains::Mountains(std::vector<std::string>& filenames)
{
    // Read the mountain names from the input files
    for (size_t i = 0; i < filenames.size(); i++) {
        std::string range = filenames[i];
        std::string filename = range + ".txt";

        std::ifstream file(filename);
        if (file.is_open()) {
            std::string mountain;
            while (getline(file, mountain)) {
                ranges[range].push_back(mountain);
            }
            file.close();
        }
    }
}

std::string Mountains::getRandomMountain()
{
    // Select a random mountain range
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<> dist(0, ranges.size() - 1);
    int index = dist(rng);
    auto it = ranges.begin();
    std::advance(it, index);
    std::string range = it->first;

    // Select a random mountain from the selected range
    std::vector<std::string>& mountains = it->second;
    std::uniform_int_distribution<> dist2(0, mountains.size() - 1);
    int index2 = dist2(rng);
    return mountains[index2];
}

bool Mountains::checkRange(std::string mountain, std::string range)
{
    // Check if the mountain is in the given range
    for (const auto& [r, mountains] : ranges) {
        if (r == range && std::find(mountains.begin(), mountains.end(), mountain) != mountains.end()) {
            return true;
        }
    }
    return false;
}
