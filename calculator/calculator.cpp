#include "calculator.h"

void Calculator::process(std::string &expr) {
    this->expression = expr;
}

double Calculator::calculation() {
    if(expressionIsCorrect()) {
        std::vector<std::string> expression = splitExpression(this->expression);
        bool isNegative = false;
        bool lastSymbolIsParenthesis = false;
        for(auto x : expression) {
            double number;
            if (x == "(") {
                lastSymbolIsParenthesis = true;
            }
            if (x != "(" && x != "-") {
                lastSymbolIsParenthesis = false;
            }
            if (x == "-" && (numbers.getSize() == 0 || lastSymbolIsParenthesis)) {
                isNegative = true;
                continue;
            }
            if ( x != "+" && x != "-" && x != "*" && x != "/" && x != "(" && x != ")"){
                number = std::stod(x);
            }
            else {
                number = 0;
            }
            if (number && isNegative) {
                number = -number;
                isNegative = false;
            }
            if (number) {
                numbers.push(number);
            }
            else {
                if (operators.getSize() == 0) {
                    operators.push(x);
                }
                else if (priority(x)) {
                    if (priority(x) <= priority(operators.lastElement())) {
                        double result = operation(numbers.pop(), numbers.pop(), operators.lastElement());
                        operators.pop();
                        numbers.push(result);
                        operators.push(x);
                    }
                    else {
                        operators.push(x);
                    }
                }
                else {
                    if (x == "(") {
                        operators.push(x);
                    }
                    if (x == ")") {
                        while (operators.lastElement() != "(") {
                            double result = operation(numbers.pop(), numbers.pop(), operators.lastElement());
                            operators.pop();
                            numbers.push(result);
                        }
                        operators.pop();
                    }
                }
            }
        }
        while (operators.getSize() != 0) {
            double result = operation(numbers.pop(), numbers.pop(), operators.lastElement());
            operators.pop();
            numbers.push(result);
        }
        return numbers.pop();
    }    
    else {
        return -1;
    }
}

bool Calculator::expressionIsCorrect() const {
    std::string expr = this->expression;
    int numberOfOpenParantheses = 0;
    int numberOfCloseParantheses = 0;
    for (int i = 0; i < expr.size(); i++) {
        if (!((int)expr[i] >= 40 && (int)expr[i] <= 43) && !((int)expr[i] >= 45 && (int)expr[i] <= 57)) {
            return false;
        }
        if ((i == 0 || i == expr.length() - 1) && (expr[i] == '+' || expr[i] == '*' || expr[i] == '/')) {
            return false;
        }
        if (expr[i] == '(') {
            numberOfOpenParantheses++;
        }
        if (expr[i] == ')') {
            numberOfCloseParantheses++;
        }
        if (i != 0 && (expr[i] == '+' || expr[i] == '*' || expr[i] == '/') && (expr[i - 1] == '+' || expr[i - 1] == '-' || expr[i - 1] == '*' || expr[i - 1] == '/' || expr[i - 1] == '(')) {
            return false;
        }
        if (i != 0 && expr[i] == '-' && (expr[i - 1] == '+' || expr[i - 1] == '-' || expr[i - 1] == '*' || expr[i - 1] == '/')) {
            return false;
        }
        if (i < expr.length() && expr[i] == ')' && expr[i + 1] != '+' && expr[i + 1] != '-' && expr[i + 1] != '*' && expr[i + 1] != '/' && expr[i + 1] != ')') {
            return false;
        }
        if (i < expr.length() && expr[i] == '(' && expr[i + 1] == '+' && expr[i + 1] == '*' && expr[i + 1] == '/' && expr[i + 1] == ')') {
            return false;
        }        
    }
    if (numberOfOpenParantheses != numberOfCloseParantheses) {
        return false;
    }
    return true;
}

std::vector<std::string> splitExpression(std::string expr){
    std::vector<std::string> vecExpr;
    std::string number = "";
    for(int i = 0; i < expr.length(); i++){
        if(isdigit(expr[i]) || expr[i] == '.'){
            number += expr[i];
        }
        if(isdigit(expr[i]) && expr[i + 1] != '.' && !isdigit(expr[i + 1])){
            vecExpr.push_back(number);
            number = "";
        }
        if(expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/' || expr[i] == '(' || expr[i] == ')'){
            std::string str = "";
            str += expr[i];
            vecExpr.push_back(str);
        }
    }
    return vecExpr;
}

int priority(std::string item) {
    if (item == "+") {
        return 1;
    }
    else if (item == "-") {
        return 1;
    }
    else if (item == "*") {
        return 2;
    }
    else if (item == "/") {
        return 2;
    }
    else if (item == "(" || item == ")") {
        return 0;
    }
    else {
        throw -1;
    }

}

double operation(const double a, const double b, std::string oper) {
    if (oper == "+") {
        return a + b;
    }
    else if (oper == "-") {
        return a - b;
    }
    else if (oper == "*") {
        return a * b;
    }
    else if (oper == "/") {
        return a / b;
    }
    else {
        throw -1;
    }
}

