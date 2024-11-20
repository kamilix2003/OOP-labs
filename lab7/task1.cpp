#include <iostream>
#include <vector>
#include <algorithm>

void print(std::vector<std::string> vec){
    for(auto item : vec) {
        std::cout << item << " ";
    }
    std::cout<< "\n";
}

int main(){
    // a + b
    std::cout << "a + b: \n";
    std::vector<std::string> shopping_list = {"wine", "beetroot", "bananas", "suger", "chocolate", "carrot"};
    print(shopping_list);
    // c
    std::cout << "c: \n";
    std::cout << shopping_list.back() << "\n";
    shopping_list.pop_back();
    print(shopping_list);
    // d
    std::cout << "d: \n";
    shopping_list.insert(shopping_list.begin() + 3, "coffee");
    print(shopping_list);
    // e
    std::cout << "e: \n";
    for(auto& item : shopping_list) {
        if (item == "suger"){
            item = "candy";
        }
    }
    print(shopping_list);
    // f 
    std::cout << "f: \n";
    for(auto& item : shopping_list) {
        if (item == "chocolate") {
            item.erase();
        }
    }
    print(shopping_list);
    // g
    std::cout<< "g: \n";
    sort(shopping_list.begin(), shopping_list.end());
    print(shopping_list);
}