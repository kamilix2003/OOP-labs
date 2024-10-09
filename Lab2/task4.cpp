#include <iostream>
#include <stdlib.h>
#include <time.h>

class SmartArray{
    unsigned int m_size;
    int* m_begin;
    int* m_end;
    
    public:
        SmartArray(unsigned int size){
            m_size = size;
            m_begin = new int[size];
            m_end = m_begin + m_size;
            for(int* i = m_begin; i < m_end; i++){ *i = 0; }
        }

        ~SmartArray(){
            // delete[] m_arr;
            std::cout<<"Array destroyed";
        }

        int* begin() const { return m_begin; }
        int* end() const { return m_end; }

        int* max(int* begin, int* end){
            int* temp = begin;
            for(int* i = begin; i < end; i++){
                if(*i > *temp) { temp = i; }
            }
            return temp;
        }
        int* min(int* begin, int* end){
            int* temp = begin;
            for(int* i = begin; i < end; i++){
                if(*i < *temp) { temp = i; }
            }
            return temp;
        }
        bool is_sorted(){
            for(int* i = m_begin + 1; i < m_end; i++){
                if(*i < *(i - 1)) return false;
            }
            return true;
        }
        void sort(bool direction){
            int sorted_elements = 0;
            int* new_max;
            while(sorted_elements != m_size){
                new_max = max(m_begin, m_end - sorted_elements);
                for(int* i = new_max; i < m_end - 1; i++){
                    if(*i > *(i+1)) {swap(i, i+1);}
                }
                sorted_elements++;
            }
            
        }

        void swap(int* ptr1, int* ptr2){
            int temp = *ptr1;
            *ptr1 = *ptr2;
            *ptr2 = temp;
        }
        
        void print(){
            for(int* i = m_begin; i < m_end; i++){ std::cout << *i << " "; }
            std::cout<< "\n";
        }
};

int main(){
    srand(time(NULL));

    SmartArray sa(10);
    sa.print();

    for(int* i = sa.begin(); i < sa.end(); i++){
        *i = rand() % 99 + 1;
    }

    sa.print();

    if(sa.is_sorted()) { std::cout<<"Array is sorted\n"; }
    else { std::cout<<"Array is not sorted\n"; }

    std::cout<<"Max value: "<<*sa.max(sa.begin(), sa.end())
    <<"\nMin value: "<<*sa.min(sa.begin(), sa.end())<<"\n";

    sa.sort(1);
    if(sa.is_sorted()) { std::cout<<"Array is sorted\n"; }
    else { std::cout<<"Array is not sorted\n"; }
    sa.print();
}