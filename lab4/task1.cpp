#include <iostream>

#include <assert.h>

class Fraction{
    int m_num;
    int m_denum;

    public:
        Fraction(int num = 0, int denum = 1){
            assert(denum != 0);
            m_num = num;
            m_denum = denum;
        }

        Fraction(Fraction& frac):
            m_num(frac.get_num()), m_denum(frac.get_denum())
        {
            std::cout<<"copied!\n";
        }

        int get_num() const {return m_num;}
        int get_denum() const {return m_denum;}
        void set_num(int num) {m_num = num;}
        void set_denum(int denum) {m_denum = denum;}

        friend Fraction operator+(const Fraction& lhs, const Fraction& rhs){
            return Fraction(lhs.m_num * rhs.m_denum + rhs.m_num * lhs.m_denum, lhs.m_denum * rhs.m_denum);
        }
        friend Fraction operator-(const Fraction& lhs, const Fraction& rhs){
            return Fraction(lhs.m_num * rhs.m_denum - rhs.m_num * lhs.m_denum, lhs.m_denum * rhs.m_denum);
        }
        friend Fraction operator*(const Fraction& lhs, const Fraction& rhs){
            return Fraction(lhs.m_num * rhs.m_num, lhs.m_denum * rhs.m_denum);
        }
        friend Fraction operator/(const Fraction& lhs, const Fraction& rhs){
            return Fraction(lhs.m_num * rhs.m_denum, lhs.m_denum * rhs.m_num);
        }
        friend std::ostream& operator<<(std::ostream& out, const Fraction& rat){
            out << rat.get_num() << "/" << rat.get_denum();
            return out;
        }
        friend std::istream& operator>>(std::istream& in, Fraction& rat){
            in >> rat.m_num;
            in >> rat.m_denum;
            return in;
        }
        friend bool operator>(const Fraction& lhs, const Fraction& rhs){
            if(lhs.m_num * rhs.m_denum > lhs.m_denum * rhs.m_num){
                return true;
            }
            else return false;
        }
        friend bool operator<(const Fraction& lhs, const Fraction& rhs){
            if(lhs.m_num * rhs.m_denum > lhs.m_denum * rhs.m_num){
                return false;
            }
            else return true;
        }
        friend bool operator==(const Fraction& lhs, const Fraction& rhs){
            if(lhs.m_num * rhs.m_denum == lhs.m_denum * rhs.m_num){
                return true;
            }
            else return false;
        }
        friend bool operator!=(const Fraction& lhs, const Fraction& rhs){
            if(lhs.m_num * rhs.m_denum == lhs.m_denum * rhs.m_num){
                return false;
            }
            else return true;
        }

        Fraction& operator++(){
            set_num(get_num()+1);
            if(get_denum() == get_num()){
                set_num(0);
            }
            return *this;
        }
        Fraction& operator++(int){
            set_num(get_num()+1);
            if(get_denum() == get_num()){
                set_num(0);
            }
            return *this;
        }
        operator double() const {return double(m_num)/double(m_denum);}
        Fraction& operator=(const Fraction& frac){
            Fraction* o = new Fraction(frac.get_num(), frac.get_denum());
            return *o;
        }
};

int main(){
    Fraction r1(3, 4);
    Fraction r2(r1);

    std::cout<<r1<<"\n"<<float(++r2++)<<"\n";
    r1 = r2;
    std::cout<<r1;

}