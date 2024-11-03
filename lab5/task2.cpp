#include <iostream>
#include <algorithm>

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
        int compare(const std::string& str){
            std::string str_temp = str;
            std::transform(begin(), end(), begin(), ::tolower);
            std::transform(str_temp.begin(), str_temp.end(), str_temp.begin(), ::tolower);
            if (contain(str_temp.data())) return true;
            else return false;
        }
};

int main(){
    NewString s1("Hello World!");
    NewString s2("hello world!");
    NewString s3("Heloo world!");
    s1.compare(s2) ? std::cout << "s1 = s2\n" : std::cout << "s1 != s2\n";
    s1.compare(s3) ? std::cout << "s1 = s3\n" : std::cout << "s1 != s3\n";
}