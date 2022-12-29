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
    // Open each file and store the mountains in the corresponding range in the map
    for (const auto& filename : filenames) {
        std::ifstream file(filename);
        std::string mountain;
        std::string range = filename;  // extract the range name from the filename
        range = range.substr(0, range.find(".txt"));  // remove the ".txt" extension from the filename
        while (std::getline(file, mountain)) {  // read each mountain name from the file
            ranges[range].push_back(mountain);  // add the mountain to the corresponding range
        }
    }
}

std::string Mountains::getRandomMountain()
{
    // Select a random range from the map
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> dist(0, ranges.size() - 1);
    auto range_it = ranges.begin();
    std::advance(range_it, dist(rng));  // move the iterator to a random position in the map
    const auto& range = range_it->first;  // get the name of the selected range


    // Select a random mountain from the selected range
    std::uniform_int_distribution<int> mountain_dist(0, range_it->second.size() - 1);
    return range_it->second[mountain_dist(rng)];  // return the randomly selected mountain
}

bool Mountains::checkRange(std::string mountain, std::string range)
{
    // Search for the mountain in the range
    for (const auto& [r, mountains] : ranges) {
        if (r == range && std::find(mountains.begin(), mountains.end(), mountain) != mountains.end()) {
            return true;  // mountain was found in the range
        }
    }
    return false;  // mountain was not found in the range
}
