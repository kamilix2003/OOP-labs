#include <iostream>

class Rational{
    int m_num;
    int m_denum;

    public:
        Rational(int num = 0, int denom = 1){
            m_num = num;
            m_denum = denom;
        }

        int get_num() const {return m_num;}
        int get_denum() const {return m_denum;}
        void set_num(int num) {m_num = num;}
        void set_denum(int denum) {m_denum = denum;}

        void add(Rational rat){
            if(m_denum == rat.get_denum()){
                m_num += rat.get_num();
                return;
            }
            else{
                m_num = m_num * rat.get_denum() + rat.get_num() * m_denum;
                m_denum *= rat.get_denum();
            }
        }

        void sub(Rational rat){
            rat.set_num(-rat.get_denum());
            add(rat);
        }

        friend Rational mult(Rational& rat1, Rational& rat2);
        friend Rational div(Rational& rat1, Rational& rat2);

        void print(){
            std::cout << "Numerator: " << m_num << "\n";
            std::cout << "Denumerator: " << m_denum << "\n";
        }
};

Rational mult(Rational rat1){
    m_num *= rat.get_num();
    m_denum *= rat.get_denum();
}


int main(){
    Rational rat1(4, 3);
    Rational rat2(3, 4);
    rat1.add(rat2);
    rat1.print();
}