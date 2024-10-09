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
    Point m_Rec_begin;
    Point m_Rec_end;

    public:
        Rectangle(float b_x = 0, float b_y = 0,
            float e_x = 1, float e_y = 1) : 
            m_Rec_begin(b_x, b_y),
            m_Rec_end(e_x, e_y) {}

        void transform(float move_x, float move_y){
            m_Rec_begin.set_x(m_Rec_begin.get_x() + move_x);
            m_Rec_end.set_x(m_Rec_end.get_x() + move_x);
            m_Rec_begin.set_y(m_Rec_begin.get_y() + move_y);
            m_Rec_end.set_y(m_Rec_end.get_y() + move_y);
        }

        float area(){
            float h = m_Rec_begin.get_x() - m_Rec_end.get_x();
            float w = m_Rec_begin.get_y() - m_Rec_end.get_y();
            return h * w;
        }

        Point* get_begin() {return &m_Rec_begin; }
        Point* get_end() {return &m_Rec_end; }
        void set_begin(Point &b) {m_Rec_begin = b;}
        void set_end(Point &e) {m_Rec_end = e;}

        void print(){
            std::cout << "Begin x=" << m_Rec_begin.get_x() << " y=" << m_Rec_begin.get_y() << "\n";
            std::cout << "End x=" << m_Rec_end.get_x() << " y=" << m_Rec_end.get_y() << "\n";
            std::cout << "Area =" << area() << "\n";
        }
};

int main(){
    std::cout<< "Original rectangle\n";
    Rectangle test_rec;
    test_rec.print();

    std::cout<< "After setter\n";
    Point new_begin(-1, -3);
    test_rec.set_begin(new_begin);
    test_rec.print();

    std::cout<< "After transform\n";
    test_rec.transform(2, 1);
    test_rec.print();

}