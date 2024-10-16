#include <iostream>

class Complex{
    float m_re;
    float m_im;

    public:
        Complex(float re = 0, float im = 0){
            m_re = re; 
            m_im = im;
        }
        float get_re() const {return m_re;}
        float get_im() const {return m_im;}
        float set_re(float re) {m_re = re;}
        float set_im(float im) {m_im = im;}

};

Complex operator+(const Complex& lhs, const Complex& rhs){
    return Complex(lhs.get_re() + rhs.get_re(), rhs.get_im() + lhs.get_im());
}

Complex operator-(const Complex& lhs, const Complex& rhs){
    return Complex(lhs.get_re() - rhs.get_re(), rhs.get_im() - lhs.get_im());
}

Complex operator*(const Complex& lhs, const Complex& rhs){
    const float re = lhs.get_re() * rhs.get_im() - lhs.get_im() * rhs.get_re();
    const float im = (lhs.get_re() + lhs.get_im())*(rhs.get_re() + rhs.get_im())
                    -(lhs.get_re() * rhs.get_re())-(lhs.get_im() * rhs.get_im());
    return Complex(re, im);
}




std::ostream& operator<<(std::ostream& out, const Complex& z){
    out << "Re: "<< z.get_re() << " Im: " << z.get_im();
    return out;
}

std::istream& operator>>(std::istream& in, Complex& z){
    float temp;
    in >> temp;
    z.set_re(temp);
    in >> temp;
    z.set_im(temp);
    return in;
}

int main(){

}