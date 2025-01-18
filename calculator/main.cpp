#include <iostream>
#include "stack.h"
#include "calculator.h"
int main(){
    Calculator calc{};
    std::string expr;
    std::cin >> expr;
    calc.setExpression(expr);
    std::cout << calc.expressionIsCorrect() << " ----" << '\n';
    double result = calc.calculation();
    std::cout << "result: "<< result << '\n'; 
    Stack<int> s;
    std::cout << s.getSize() << '\n';
    s.push(10);
    int a = s.pop();
    std::cout << s.getSize() << '\n';
    /*s.push(12);
    s.push(13);
    s.push(14);
    s.push(15);
    s.push(16);
    s.push(17);
    std::cout << s.getSize() << '\n';
    std::cout << a << '\n';
    Stack<int> s2 = s;
    s2.push(17);
    Stack<int> s1;
    if (s1 < s){
        std::cout << "yes" << '\n';
    }
    std::cout << s[0];*/
}