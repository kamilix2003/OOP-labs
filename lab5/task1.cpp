#include <iostream>

class MyString : public std::string{

    public:
        MyString(const char* str = "") : std::string(str){
            std::cout<<"MyString constructor called\n";
        }
        ~MyString(){
            std::cout<<"MyString destructor called\n";
        }
        MyString& to_upper(){
            for(char* i = data(); i < data() + size(); i++){
                if(*i >= 97 && *i <= 122){
                    *i -= 32;
                }
            }
            return *this;
        }
};

std::ostream& operator<<(std::ostream& out, MyString& str){
    out << str.data();
    return out;
}

class Figure{
    double m_x, m_y;
    MyString m_label;

    public:
        Figure(double x = 0, double y = 0, const char* label = "") :
            m_x(x), m_y(y), m_label(label)
        {
            std::cout<<"Figure constructor called\n";
        }
        ~Figure(){
            // delete &mlabel, m_x, m_y;
            std::cout<<"Figure destructor called\n";
        }
        double get_x() const {return m_x;}
        double get_y() const {return m_y;}
        MyString get_label() {return m_label;}
        void print(void){
            std::cout<< "I'm figure " << "\nx = " << m_x 
                << "\ny = " << m_y 
                << "\nlabel = " << m_label.to_upper() << "\n";
        }
};

class Rectangle : public Figure{
    double m_w, m_h;

    public:
        Rectangle(double x = 0, double y = 0, double w = 0, double h = 0, const char* label = "") :
            Figure(x, y, label), m_w(w), m_h(h){
            std::cout<<"Rectangle constructor called\n";
        }
        ~Rectangle(){
            // delete &m_w;
            // delete &m_h;
            std::cout<<"Rectangle constructor called\n";
        }
        double get_w() const { return m_w;}
        double get_h() const { return m_h;}
        void print(void){
        std::cout<< "I'm Rectangle " << "\nx = " << get_x()
            << "\ny = " << get_y() 
            << "\nlabel = " << get_label().to_upper() << "\n";
        }
};

class Square : Rectangle{
    public:
        Square(double x = 0, double y = 0, double w = 0, const char* label = "")
        : Rectangle(x, y, w, w, label){
            std::cout<<"Rectangle constructor called\n";
        }
        ~Square(){
            std::cout<<"Square destructor called\n";
        }
        void print(void){
        std::cout<< "I'm Square " << "\nx = " << get_x()
            << "\ny = " << get_y() 
            << "\nlabel = " << get_label().to_upper() << "\n";
        }
};

int main(){
    // a.
    Figure f1;

    // b.
    Rectangle r1;

    // c.
    Square s1;

    // d.
    Square s2(1, 2, 10, "square 1");
    s2.print();

    // 6. Figure
}