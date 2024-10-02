#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

int main(){
    srand(time(NULL));
    bool array_not_full = true;
    std::vector<int> random_nums;
    while(array_not_full){
        random_nums.push_back(rand() % 9 + 1;);
    }
}