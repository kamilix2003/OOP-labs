#include <iostream>

class Int{
    int m_num;

    public:
        void clear() {m_num = 0;}
        void set(int num) {m_num = num;}
        int get_num() const {return m_num;}

        int add(Int& num1){
            return m_num + num1.get_num();
        }

        void print(bool hex){
            if(hex){
                std::cout << std::hex << m_num << "\n";
            }
            else{
                std::cout << m_num << "\n";
            }
        }
};

int main(){
    Int ni1;
    ni1.set(3);
    Int ni2;
    ni2.set(9);
    Int nui;
    nui.set(ni1.add(ni2));
    nui.print(0);
    nui.print(1);
}