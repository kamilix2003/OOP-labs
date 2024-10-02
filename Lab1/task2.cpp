#include <iostream>
#include <string>
int main(){
    std::string user_input, inverted_input;
    std::cout << "Write something: "; 
    std::cin >> user_input;
    // std::cout << user_input << std::endl;

    size_t input_size = user_input.size();
    for(int i = input_size; i >= 0 ; i--)
    {
        // std::cout << user_input[i] << std::endl;
        // inverted_input.append(user_input);
        inverted_input += user_input[i];
    }
    std::cout << "Inverted input: "<< inverted_input << std::endl;
}