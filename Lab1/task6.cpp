#include <iostream>

int main(){
    char lookup[7] = {'t', 's', 'e', 'b', 's', 'i', 'C'};
    for(int row = 7; row > 0; row--){
        for(int col = 0; col < 6; col++){
            if(row != col) std::cout<< " ";
            else std::cout << lookup[col];
        }
        for(int col = 6; col >= 0; col--){
            if(row != col) std::cout<< " ";
            else std::cout << lookup[col];
        }
        std::cout << "\n";
    }
    for(int col = 0; col < 6; col++){
        std::cout << lookup[col];
    }
    for(int col = 6; col >= 0; col--){
        std::cout << lookup[col];
    }
    std::cout << "\n";
}