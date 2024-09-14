#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int x = 0;
    //считаем левую часть
    cout << "enter the power of e" << endl;
    cin  >> x;
    cout << exp(x) << endl;
    //считаем правую часть
    int f = 1;
    for (int p = 0;p < 10; p++){
        f = f*(p+1);
        int x1 = pow(x,p);
    }
    cout << f;



}