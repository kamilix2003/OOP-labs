#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

const int TICKET_COUNT = 5;

class Lottery{
    private:
        int tickets[TICKET_COUNT];
        int new_ticket;

    public:
        Lottery(){
            for(int i = 0; i < TICKET_COUNT; i++){
                tickets[i] = 0;
            }
        }

        void roll(){
            for(int n_ticket = 0; n_ticket < TICKET_COUNT; n_ticket++){
                // std::cout<< n_ticket << std::endl;
                do{
                    new_ticket = rand() % TICKET_COUNT + 1;
                    tickets[n_ticket] = new_ticket;
                    // std::cout<< new_ticket << std::endl;
                }
                while(repeated_ticket(new_ticket, n_ticket));
            }
        }

        bool repeated_ticket(int new_ticket, int current_ticket){
            for(int i = 0; i < TICKET_COUNT; i++){
                if(i != current_ticket && tickets[i] == new_ticket) return true;
            }
            return false;
        }

        void display_tickets(){
            std::cout<< "Drawned tickets: ";
            for(int i = 0; i < TICKET_COUNT; i++){
                std::cout<< tickets[i] << ", ";
            }
        }
};

int main(){
    srand(time(NULL));
    Lottery my_lottery;
    my_lottery.roll();
    my_lottery.display_tickets();
}