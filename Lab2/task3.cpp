#include <iostream>

class Student{
    std::string m_name;
    unsigned int m_id;
    float m_grade;

    public:
        Student(std::string name, unsigned int id, float grade){
            m_name = name;
            m_id = id;
            m_grade = grade;
        }

        void set_name(std::string name){ m_name = name; }
        void set_id(unsigned int id){ m_id = id; }
        void set_grade(float grade){ m_grade = grade; }
        std::string get_name() const { return m_name; }
        unsigned int get_id() const { return m_id; }
        float get_grade() const { return m_grade; }

        void print(){
            std::cout<< "Name: " << m_name << "\n"; 
            std::cout<< "id: " << m_id << "\n"; 
            std::cout<< "Grade: " << m_grade << "\n"; 
        }
};

int main(){
    Student s1("Kamil", 9, 4.41);
    Student s2("Patrycja", 5, 4.18);
    Student s3("Konrad", 12, 4.17);
    Student* students[3] = {&s1, &s2, &s3};
    s1.print();
    float avg_grade = 0;
    for(Student* s : students){
        avg_grade += s->get_grade();
    }
    avg_grade /= 3;
    std::cout<<"Average grade: " << avg_grade;
}