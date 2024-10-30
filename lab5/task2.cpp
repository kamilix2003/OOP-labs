#include <iostream>

class NewString : public std::string{
    public:
        NewString(const char* str = "") : std::string(str){
        }
        NewString(std::string& str) : std::string(str){
        }
        bool contain(const char* str){
            if(find(str) == std::string::npos) return false;
            return true;
        }
        int compare(const string& str){
            std::
        }
};

int main(){

}