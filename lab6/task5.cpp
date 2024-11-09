#include <iostream>
#include <exception>

class Average_exception : public std::exception {
private:
    const char* m_err_msg;
public:
    Average_exception(const char* err) : m_err_msg(err) {}
    const char* what() { return m_err_msg; }
};

bool out_of_bound(int x) {
    if (x > 100 || x < 0) return true;
    return false;
}

float calculateAverage(int m1, int m2, int m3, int m4) {
    
    if(out_of_bound(m1) ||
    out_of_bound(m2) ||
    out_of_bound(m3) ||
    out_of_bound(m4)) {
        throw Average_exception("OutOfRangeException");
    }
    return float(m1 + m2 + m3 + m4)/4;

}

int main() {
    int marks[2][4] = {{65, 49, 0, 100}, {-1, 99, 101, 69}};
    try {
        std::cout<< "Average mark: " << calculateAverage(marks[0][0], marks[0][1], marks[0][2], marks[0][3]) << "\n";
    }
    catch (Average_exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
    try {
        std::cout<< "Average mark: " << calculateAverage(marks[1][0], marks[1][1], marks[1][2], marks[1][3]) << "\n";
    }
    catch (Average_exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}