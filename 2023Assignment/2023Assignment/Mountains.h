#include<vector>
#include<string>
#include<iostream>

#ifndef MOUNTAINS_H
#define MOUNTAINS_H
class Mountains
{
public:
	std::map<std::string, std::vector<std::string>> ranges;  // map of mountain ranges to mountain names
	
	//Time complexity: 
	Mountains(std::vector<std::string>& filenames);

	//Time complexity:
	std::string getRandomMountain();

	//Time complexity:
	bool checkRange(std::string mountain, std::string range);
};
#endif
