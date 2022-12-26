#include<vector>
#include<string>
#include<iostream>

#ifndef MOUNTAINS_H
#define MOUNTAINS_H
class Mountains
{
public:
	//Time complexity: 
	Mountains(std::vector<std::string>& filenames);

	//Time complexity:
	std::string getRandomMountain();

	//Time complexity:
	bool checkRange(std::string mountain, std::string range);
};
#endif
