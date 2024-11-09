#include <iostream>
#include <tuple>
#include <cmath>

void get_parameters(double* a, double* b, double* c){
    std::cout<<"input a: ";
    std::cin>>*a;
    std::cout<<"input b: ";
    std::cin>>*b;
    std::cout<<"input c: ";
    std::cin>>*c;
}

void quadratic(const double a, const double b, const double c,
    std::tuple<double, double>& roots){
    const double delta = b*b - 4*a*c;

    try{
        if(delta < 0){
            // throw "Equation has no real solution";
            throw 15;
            std::cout<<"this never prints";
        }
    }
    // catch(const char* exception){
    catch(int exception) {
        std::cout<< "Error: " << exception << "\n";
    }

    roots = {(-b - sqrt(delta))/(2*a), (-b + sqrt(delta))/(2*a)};

}

int main(){
    double a, b, c;
    std::tuple<double, double> results;
    get_parameters(&a, &b, &c);
    quadratic(a, b, c, results);
    std::cout<< "Roots: " <<std::get<0>(results)<<", "<<std::get<1>(results);
}