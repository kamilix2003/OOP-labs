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
        void set_re(float re) {m_re = re;}
        void set_im(float im) {m_im = im;}

};

Complex operator+(const Complex& lhs, const Complex& rhs){
    return Complex(lhs.get_re() + rhs.get_re(), rhs.get_im() + lhs.get_im());
}

Complex operator-(const Complex& lhs, const Complex& rhs){
    return Complex(lhs.get_re() - rhs.get_re(), lhs.get_im() - rhs.get_im());
}

Complex operator*(const Complex& lhs, const Complex& rhs){
    const float re = lhs.get_re() * rhs.get_im() - lhs.get_im() * rhs.get_re();
    const float im = (lhs.get_re() + lhs.get_im())*(rhs.get_re() + rhs.get_im())
                    -(lhs.get_re() * rhs.get_re())-(lhs.get_im() * rhs.get_im());
    return Complex(re, im);
}

Complex operator/(const Complex& lhs, const Complex& rhs){
    const float denom = (rhs.get_re() * rhs.get_re()) + (rhs.get_im() * rhs.get_im());
    const float re = ((lhs.get_re() * rhs.get_re()) + (lhs.get_im() * rhs.get_im())) / denom;
    const float im = ((lhs.get_im() * rhs.get_re()) - (lhs.get_re() * rhs.get_im())) / denom;
    return Complex(re, im);
}

std::ostream& operator<<(std::ostream& out, const Complex& z){
    if(z.get_im() >= 0)
        out << z.get_re() << " + i" << z.get_im();
    else 
        out << z.get_re() << " - i" << -z.get_im();
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
    Complex z1, z2;
    std::cout << "1st complex number: ";
    std::cin >> z1;
    std::cout << "2nd complex number: ";
    std::cin >> z2;

    std::cout << "z1 + z2 = " << z1 + z2 << std::endl;
    std::cout << "z1 - z2 = " << z1 - z2 << std::endl;
    std::cout << "z1 * z2 = " << z1 * z2 << std::endl;
    std::cout << "z1 / z2 = " << z1 / z2 << std::endl;

}