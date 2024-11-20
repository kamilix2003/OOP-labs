#include <iostream>
#include <time.h>
#include <vector>

void print(std::vector<double> vec){
    for(auto item : vec) {
        std::cout << item << " ";
    }
    std::cout<< "\n";
}

std::vector<double> sum(std::vector<double> v1, std::vector<double> v2){
    std::vector<double> v3 = v1;
        for(int i = 0; i < v2.size(); i++){
            v3[i] += v2[i];
        }
    return v3;
}

int main(){
    std::vector<double> v1;
    std::vector<double> v2;
    srand(time(NULL));
    for(int i = 0; i < 4; i++){
        v1.push_back((rand() % 99 + 1));
        v2.push_back((rand() % 99 + 1));
    }
    print(v1);
    print(v2);
    std::vector<double> v3 = sum(v1, v2);
    print(v3);

}