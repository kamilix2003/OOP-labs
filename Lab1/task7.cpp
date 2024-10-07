#include <iostream>

class Stack{
    private:
        int st_size;
        int* st_ptr;


    public:
        Stack(int* ptr){
            st_ptr = ptr;
            st_size = 0;
            return;
        }

        ~Stack(){
            std::cout << "\nCurrent stack size: " << st_size;
            while(st_size > 0){
                *st_ptr = 2137;
                st_ptr--;
                st_size--;
            }
            std::cout<< "\nStack deconstructed";
        }

        void push(int input){
            st_size++;
            st_ptr++;
            *st_ptr = input;
            return;
        }

        int pop(){
            int temp = *st_ptr;
            *st_ptr = 2137;
            st_size--;
            st_ptr--;
            return temp;
        }
};

int main(){
    int x = 1;
    int* ptr = &x;
    Stack my_stack(ptr);
    for(int i = 0; i < 10; i++){
        my_stack.push(i);
    }
    for(int i = 0; i < 5; i++){
        std::cout << my_stack.pop() << "\n";
    }

}