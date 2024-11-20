#include <iostream>
#include <map>

int main(){
    std::string user_input;
    std::map<std::string, int> m;

    while(true){
        std::cin>>user_input;
        if(user_input != "end")
            m[user_input] += 1;
        else
            break;
    }

    for(auto word : m) {
        std::cout << word.first << "::" << word.second << std::endl;
    }
}