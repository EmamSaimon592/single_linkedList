
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed random number generator
    std::srand(std::time(nullptr));

    std::string choices[3] = {"rock", "paper", "scissors"};

    std::cout << "Welcome to Rock Paper Scissors!\n";
    std::cout << "Enter your choice: rock, paper, or scissors (or 'quit' to exit).\n\n";

    std::string userChoice;
    while (true) {
        std::cout << "Your choice: ";
        std::cin >> userChoice;

        if (userChoice == "quit") {
            break;
        }

        // Validate user input
        int userIndex = -1;
        if (userChoice == "rock") userIndex = 0;
        else if (userChoice == "paper") userIndex = 1;
        else if (userChoice == "scissors") userIndex = 2;

        if (userIndex == -1) {
            std::cout << "Invalid choice! Please enter rock, paper, or scissors.\n\n";
            continue;
        }

        // Computer's random choice
        int computerIndex = std::rand() % 3;
        std::cout << "Computer chose: " << choices[computerIndex] << "\n";

        // Determine winner
        if (userIndex == computerIndex) {
            std::cout << "It's a tie!\n";
        }
        else if ((userIndex == 0 && computerIndex == 2) ||  // rock beats scissors
                 (userIndex == 1 && computerIndex == 0) ||  // paper beats rock
                 (userIndex == 2 && computerIndex == 1)) {  // scissors beats paper
            std::cout << "You win!\n";
        }
        else {
            std::cout << "Computer wins!\n";
        }

        std::cout << "\n";
    }

    std::cout << "Thanks for playing!\n";
    return 0;
}
