#include <iostream>

class InvalidIndex {
private:
    const char* m_err_msg;
public:
    InvalidIndex(const char* err) : m_err_msg(err){}
    const char* what() {
        return m_err_msg;
    };
};

class InvalidValue {
private:
    const char* m_err_msg;
public:
    InvalidValue(const char* err) : m_err_msg(err){}
    const char* what() {
        return m_err_msg;
    };
};

class StaticArray {
private:
    unsigned int m_arr[16];
public:
    StaticArray() {
        for(int i = 0; i < 16; i++){
            m_arr[i] = i;
        }
    }
    int at(int index) {
        if ( index < 0 || index > 15) throw InvalidIndex("Out of range");
        return m_arr[index];
    }
    void set_item(int index, int value){
        if ( index < 0 || index > 15) throw InvalidIndex("Out of range");
        if ( value < 0 ) throw InvalidValue("Negative value");
        m_arr[index] = value;
    }
};

int main() {
    StaticArray arr;
    int indices[3] = {-1, 5, 18};
    int values[3] = {-1, 5, 18};
    for(int index : indices){
        try {
            std::cout << "Value at index " << index << " = " << arr.at(index) << "\n";
        }
        catch (InvalidIndex& e) {
            std::cerr << e.what() << "\n";
        }
        catch (InvalidValue& e) {
            std::cerr << e.what() << "\n";
        }
        catch (...) {}
    }

    for(int value : values){
        try {
            arr.set_item(indices[1], value);
        }
        catch (InvalidIndex& e) {
            std::cerr << e.what() << "\n";
        }
        catch (InvalidValue& e) {
            std::cerr << e.what() << "\n";
        }
        catch (...) {}
    }

        for(int value : values){
        try {
            arr.set_item(indices[0], value);
        }
        catch (InvalidIndex& e) {
            std::cerr << e.what() << "\n";
        }
        catch (InvalidValue& e) {
            std::cerr << e.what() << "\n";
        }
        catch (...) {}
    }
}