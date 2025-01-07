#include <iostream>
#include "stack.h"
#include <string>
#include <vector>
class Calculator {
public:
    Calculator(){};
    double calculation();
    void setExpression(std::string &expr);
    bool expressionIsCorrect() const;
private:
    Stack<double> numbers;
    Stack<std::string> operators;
    std::string expression;
};

std::vector<std::string> splitExpression(std::string expr);
int priority(std::string item);
double operation(const double a, const double b, std::string oper);