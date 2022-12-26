#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "Mountains.h"

int main()
{
	std::vector<std::string> filenames = {"alps.txt", "pyrenees.txt", "carpathians.txt", "icelandic_highlands.txt"};
	    Mountains mountains(filenames);
	    std::cout << "ranges:" << std::endl;
	        for (const auto& [range, mountains] : mountains.ranges) {
			        std::cout << range << ": ";
				        for (const auto& mountain : mountains) {
						            std::cout << mountain << " ";
							            }
					        std::cout << std::endl;
						    }

		    return 0;
}
