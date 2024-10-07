#include <iostream>
#include <string>

void permutate(std::string str, int idx){
    if(idx == str.size() - 1){
        std::cout<<str<<std::endl;
        return;
    }
    for(int i = idx; i < str.size(); i++){
        std::swap(str[idx], str[i]);
        permutate(str, idx + 1);
        std::swap(str[idx], str[i]);
    }
}

int main(){
    permutate("abc", 0);
}