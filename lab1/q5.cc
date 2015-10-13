#include <cstdlib> // for atoi and rand
#include <ctime> // for time
#include <iostream>

int main(void) {
    std::srand(std::time(NULL)); // seed for RNG
    int rand = std::rand()%100 + 1;
    int guess = 1;
    while(true) {
        std::cout << "Guess the number between 1 and 100 (-1 to exit):" << std::endl;
        std::cin >> guess;
        if(guess == -1)
            break;
        else if(guess == rand) {
            std::cout << "Correct! You win!" << std::endl;
            return 0;
        }
        std::cout << "Try again" << std::endl;
    }
    std::cout << "Goodbye" << std::endl;
    return 0;
}

