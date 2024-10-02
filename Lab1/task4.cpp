#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

const int TICKET_COUNT = 5;

class Lottery{
    private:
        srand(time(NULL));
        int tickets[TICKET_COUNT];

    void roll(){
        int new_ticket = rand() % 9 + 1;

    }

    bool repeated_ticket(int new_ticket){
        
    }
}

int main(){
}