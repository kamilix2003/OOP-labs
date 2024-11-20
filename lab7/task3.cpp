#include <iostream>
#include <map>

int main(){
    std::map<std::string, unsigned int> phone_book;
    phone_book["kamil"] = 784;
    phone_book["konrad"] = 983;
    phone_book["patrycja"] = 112;

    std::string user_input;
    while(true){
        std::cout << "Enter name: ";
        std::cin >> user_input;

        if(user_input == "exit"){
            return 0;
        }

        if(phone_book.count(user_input) > 0) {
            std::cout<< user_input << "'s phone number: " <<phone_book[user_input]<<"\n";
        }
        else {
            std::cout<<"there is no user called: " << user_input << "\n";
            std::cout<<"Enter phone number for " << user_input << " : ";
            std::cin >> phone_book[user_input];
        }
    }
}