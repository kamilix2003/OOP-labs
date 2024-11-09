#include <iostream>
#include <exception>
#include <fstream>

void copy_file(const std::string& og_file, const std::string& new_file){
    std::ifstream in_file(og_file);
    std::ofstream out_file(new_file);
    char c;
    while(in_file.get(c)) {
        out_file << c;
    }
    out_file.close();
}

int main(){
    copy_file("file.txt", "copied_file.txt");
    std::ifstream file;
    file.exceptions(std::ifstream::failbit|std::ifstream::badbit);
    try {
        file.open("copied_file.txt");
        char c;
        while(file.get(c)){
            std::cout << c << " ";
        }
        file.clear();
        file.close();
    }
    catch(std::ifstream::failure& e) {
        std::cout << "\nError: " << e.what() << "\n";
    }
}

