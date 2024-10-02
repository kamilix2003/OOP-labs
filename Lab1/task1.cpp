#include <iostream>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(NULL));

    int random_number = rand() % 100 + 1;
    int user_guess;
    std::cout << random_number << std::endl;

    std::cout << "Guess number from 1 to 100" << std::endl;

    for(int try_count = 7; try_count >= 0; try_count--){
        std::cin >> user_guess;
        if (user_guess == random_number){
            std::cout << "You guessed correctly" << std::endl;
            std::cout << "Random number is " << random_number << std::endl;
            return 0;
        }
        else{
            if(try_count == 0) break;
            user_guess > random_number ? std::cout << "Too high!\n" : std::cout << "Too low!\n";
            std::cout << "You guessed incorrectly\nTry again, " << try_count << " tries left" << std::endl;
        }
    }
    std::cout<< "Game over";
    return 0;
}