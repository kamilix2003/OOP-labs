#include <iostream>

class Calculator{
    public:
    float input1, input2, result;
    char op;

    void get_inputs(){
        std::cout << "Input 1: ";
        std::cin >> input1;
        std::cout << "Input 2: ";
        std::cin >> input2;
    }

    void add(){
        get_inputs();
        result = input1 + input2;
    }

    void sub(){
        get_inputs();
        result = input1 - input2;
    }

    void div(){
        get_inputs();
        if(input2 == 0){
            std::cout << "Division by zero\n";
            result = 999;
            return;
        }
        result = input1 / input2;
    }

    void mult(){
        get_inputs();
        result = input1 * input2;
    }

    void select_operator(){
        std::cin >> op;
        switch (op)
        {
        case '+':
            add();
            break;

        case '-':
            sub();
            break;

        case '/':
            div();
            break;

        case '*':
            mult();
            break;
        
        default:
            std::cout << "Unknown oparator\n";
            result = 999;
            break;
        }
    }
};

int main(){
    Calculator calc; char op; float result;
    while(true){
        std::cout << "Select operation(+, -, /, *): ";
        calc.select_operator();
        std::cout << "Result: " << calc.result << std::endl;
    }
}