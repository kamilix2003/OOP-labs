#include <iostream>

#define OCT_1 (0x000000FF)
#define OCT_2 (0x0000FF00)
#define OCT_3 (0x00FF0000)
#define OCT_4 (0xFF000000)

class IP{
    unsigned int m_ip;

    public:
        unsigned int get_ip() const {return m_ip;}
        void set_ip(unsigned int ip) {m_ip = ip;}
};

std::ostream& operator<<(std::ostream& out, IP& addr){
    out << ((addr.get_ip() & OCT_4) >> 24) << ".";
    out << ((addr.get_ip() & OCT_3) >> 16) << ".";
    out << ((addr.get_ip() & OCT_2) >> 8) << ".";
    out << (addr.get_ip() & OCT_1);
    return out;
}

int main(){
    IP ip_addr;
    ip_addr.set_ip(0xFFFFFFFF);
    std::cout<<ip_addr<<"\n";
    ip_addr.set_ip(0xC0A80001);
    std::cout<<ip_addr;
}