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
            delete[] m_begin;
            std::cout<<"Array destroyed"<<"\n";
        }
        SmartArray(SmartArray& arr){
            m_size = arr.get_size();
            int* table = new int[m_size];
            m_begin = table;
            for(int* i = arr.begin(); i < arr.end(); i++){
                *table = *i;
                table++;
            }
            m_end = table;
        }
        int get_size() const {return m_size;}
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
            if(direction){
                invert();    
            }
        }
        void invert(){
            int* temp = new int[m_size];
            for(int* i = m_begin; i < m_end; i++){
                *temp = *i;
                temp++;
            }
            for(int* i = m_begin; i < m_end; i++){
                temp--;
                *i = *temp;
            }
            delete temp;
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
        int& operator[] (const int index){
            return *(m_begin + index);
        }
        void operator= (const SmartArray& arr){
            m_size = arr.get_size();
            m_begin = arr.begin();
            m_end = arr.end();
        }
};

std::ostream& operator<<(std::ostream& out, const SmartArray& arr){
    for(int* i = arr.begin(); i < arr.end(); i++){
        out<<*i<<" ";
    }
    return out;
}

int main(){
    srand(time(NULL));

    SmartArray sa1(10);

    for(int* i = sa1.begin(); i < sa1.end(); i++){
        *i = rand() % 99 + 1;
    }
    sa1.print();

    SmartArray sa2(sa1);
    sa2.print();

    sa2[4] = 3;
    std::cout<<"4th element: "<<sa2[4]<<"\n";

    std::cout<< "sa2: " << sa2 << "\n";
}