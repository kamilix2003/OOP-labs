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

        friend void mult(Rational& rat1, Rational& rat2){
            rat1.m_num *= rat2.m_num;
            rat1.m_denum *= rat2.m_denum;
        }
        friend void div(Rational& rat1, Rational& rat2){
            rat1.m_num *= rat2.m_denum;
            rat1.m_denum *= rat2.m_num;
        }

        void print(){
            std::cout << "Numerator: " << m_num << "\n";
            std::cout << "Denumerator: " << m_denum << "\n";
        }
};

int main(){
    Rational rat1(1, 3);
    Rational rat2(1, 2);

    std::cout<<"\nadd\n";
    rat1.add(rat2);
    rat1.print();

    std::cout<<"\nsub\n";
    rat1.sub(rat2);
    rat1.print();

    std::cout<<"\nmult\n";
    mult(rat1, rat2);
    rat1.print();

    std::cout<<"\ndiv\n";
    div(rat1, rat2);
    rat1.print();
}