#include <iostream>

class Point{
    float m_x;
    float m_y;

    public:
        Point(float x = 0, float y = 0){
            m_x = x;
            m_y = y;
        }

        void set_x(float x) {m_x = x;}
        void set_y(float y) {m_y = y;}

        float get_x() const {return m_x;}
        float get_y() const {return m_y;}

};

class Rectangle{
    Point* points[2];

    public:
        Rectangle
};

int main(){



    // Point p;
    // std::cout<<p.get_x()<< ", "<<p.get_y()<<std::endl;
    // p.set_x(21.37);
    // p.set_y(3.14);
    // std::cout<<p.get_x()<< ", "<<p.get_y()<<std::endl;
}