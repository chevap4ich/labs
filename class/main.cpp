#include <iostream>
#include "fraction.h"

int main(){
    Fraction f1(-35, 36);
    std::cout << f1 << '\n';
    Fraction f2(4, 76);
    std::cout << f1.addition(f2) << '\n';
    std::cout << f1.division(f2) << '\n';
=======
#include <iostream>
#include "fraction.h"

int main(){
    Fraction f1(-35, 36);
    std::cout << f1 << '\n';
    Fraction f2(4, 76);
    std::cout << f1.addition(f2) << '\n';
    std::cout << f1.division(f2) << '\n';
}
