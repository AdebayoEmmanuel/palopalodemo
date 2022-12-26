#include <iostream>
#include <string>
#include <vector>

#include "Mountains.h"

int main()
{
    // Read the mountain names from the input files
    std::vector<std::string> filenames = {"alps.txt", "pyrenees.txt", "carpathians.txt", "icelandic_highlands.txt"};
    Mountains mountains(filenames);

    // Start the quiz
    std::string input;
    int correct_answers = 0;
    int questions_asked = 0;
    while (true) {
        // Get a random mountain
        std::string mountain = mountains.getRandomMountain();
        std::cout << "Which range is " << mountain << " in?" << std::endl;
        std::getline(std::cin, input);

        // Check if the user wants to exit
        if (input == "exit" || input == "quit") {
            break;
        }

        // Check the answer
        if (mountains.checkRange(mountain, input)) {
            std::cout << "Correct!" << std::endl;
            correct_answers++;
        } else {
            std::cout << "Incorrect." << std::endl;
        }
        questions_asked++;
    }

    // Print the score
    std::cout << "You answered " << correct_answers << " out of " << questions_asked << " questions correctly." << std::endl;
    return 0;
}
