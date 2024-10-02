#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
    double x = 0;
    cout << "enter the power of e" << endl;
    cin  >> x;
    
    //считаем правую часть
    double k = 0;//минус степень 10
    cout << "enter the number >1" << endl;
    cin >> k;
    int n = 0;
    cout << "kolichestvo znakov posle zapyatoy -" << endl;
    cin >> n;
    double x1 = 1; //х в степени р
    double sum = 1; //сумма
    for (int p = 1;p >= 0; p++){
        if (k <= 1){ //проверка k
            cout << "wrong number, try again";
            return(0);
        }
        x1 = (x1 * x) / p;
        sum = sum + x1;
        if (abs(x1) < pow(10,-k)){
            break;
        }
    }
    cout << "exp = ";
    cout << fixed << setprecision(n) << exp(x) << endl;
    cout << "approximate value = ";
    cout << fixed << setprecision(n) << sum;
    return 0;
}