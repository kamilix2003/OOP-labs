#include <iostream>

class Time{
    int m_hour;
    int m_min;
    int m_sec;

    public:
        Time(int hour = 0, int min = 0, int sec = 0){
            m_hour = hour;
            m_min = min;
            m_sec = sec;
        }
        int get_hour() const {return m_hour;}
        int get_min() const {return m_min;}
        int get_sec() const {return m_sec;}
        void set_hour(int hour) {m_hour = hour;}
        void set_min(int min) {m_min = min;}
        void set_sec(int sec) {m_sec = sec;}
        void print(){
            std::cout<< "Current time: " << m_hour << ":" << m_min << ":" << m_sec << "\n";
        }
    operator std::string(){
        
    }

};

Time operator+(const Time& lhs, const Time& rhs){
    int h, m, s;
    h = lhs.get_hour() + rhs.get_hour();
    h %= 24;

    m = lhs.get_min() + rhs.get_min();
    if(m >= 60){
        h += m/60;
        m = m%60;
    }
    s = lhs.get_sec() + rhs.get_sec();
    if(s >= 60){
        m += s/60;
        s = s%60;
    }
    
    return Time(h, m, s);
}

bool operator>(const Time& lhs, const Time& rhs){
    if(lhs.get_hour() < rhs.get_hour()) {return false;}
    else if(lhs.get_min() < rhs.get_min()) {return false;}
    else if(lhs.get_sec() < rhs.get_sec()) {return false;}
    return true;
}

int main(){
    Time t1(12, 30, 0);
    Time t2(12, 30, 1);
    t1.print();
    t2.print();
    Time t3 = t1 + t2;
    t3.print();
    (t1>t2) ? std::cout<<"t1 greater\n" : std::cout<<"t2 greater\n";
}