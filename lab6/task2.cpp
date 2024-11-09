#include <iostream>
#include <sstream>
#include <exception>
#include <string>


int main(){

    std::string str;
    std::cout<< "Input string: ";
    std::cin >> str;
    int int_str;
    try {
        int_str = std::stoi(str);
    }
    catch(const std::invalid_argument& ia) {
        std::cerr << "Error: Invalid argument";
    }
    catch(const std::out_of_range& oor) {
        std::cerr << "Error: Out of range";
    }
    catch (...) {
        std::cerr << "All catch error";
    }
    std::stringstream ss;
    ss << std::hex << int_str;
    std::cout << "0x" << ss.str();
}