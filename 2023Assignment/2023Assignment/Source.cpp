#include <iostream>
#include <string>
#include <vector>

#include "Mountains.h"

int main()
{
// Read the mountain names from the input files
std::vectorstd::string filenames = {"Alps.txt", "Pyrenees.txt", "Carpathians.txt", "Icelandic Highlands.txt"};
Mountains mountains(filenames);

// Start the quiz
std::string input;
int correct_answers = 0;
int questions_asked = 0;
while (input != "exit" && input != "quit") {
    std::string mountain = mountains.getRandomMountain();
    std::cout << "Which mountain range is " << mountain << " in? (Enter 'exit' or 'quit' to end the quiz)" << std::endl;
    std::cin >> input;

    if (mountains.checkRange(mountain, input)) {
        correct_answers++;
    }
    questions_asked++;
}

// Display the final score
std::cout << "Your score is " << correct_answers << "/" << questions_asked << std::endl;

return 0;
}
