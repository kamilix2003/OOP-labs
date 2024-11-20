#include <map>
#include <iostream>

int main(){
    std::string user_input;
    std::map<char, int> freq_char;

    std::cout<< "Type something: ";
    std::cin>> user_input;

    for(auto c : user_input) {
        freq_char[c]++;
    }

    for(auto element : freq_char) {
        std::cout << element.first << " was typed " << element.second << " times\n";
    }
}