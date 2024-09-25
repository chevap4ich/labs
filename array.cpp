#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
    srand(time(0));
    const int maxSize = 30;
    int size;
    int maxValue, minValue;
    int x;
    int pr = 1;
    int zeros = 0;
    int sum = 0;
    cout << "size of array(30 max) - ";
    cin >> size;
    if (size > maxSize || size <= 1){
        cout << "try again";
        return 0;
    }
    double* d_arr = new double[size];
    cout << "fill the array 1.with keyboard 2.randomly (enter the number of choice) ";
    cin >> x;
    if (x != 1 && x != 2){
        return 0;
    }
    if (x == 1){
        cout << "enter the elemets ";
        for (int i = 0; i < size; i++){
            cin >> d_arr[i];
        }
    }
    if (x == 2){
        cout << "enter the interval bounderies" << endl;
        cout << "min - ";
        cin >> minValue;
        cout << "max - ";
        cin >> maxValue;
        for (int i = 0; i < size; i++){
            d_arr[i] = rand() % (maxValue - minValue +1) + minValue;
            cout << d_arr[i] << " ";
        }
    }
    for (int i = 1; i < size; i += 2){
            pr = pr*d_arr[i];
    }
    cout << endl << "product = " << pr << endl;
    for (int i = 0; i < size; i++){
            if (d_arr[i] == 0){
                zeros++;
            }
    }
    int c = 0;
    for (int i = 0; i < size; i++){
            if (d_arr[i] == 0){
                for (i; i < size && c < zeros; i++){
                    sum = sum + d_arr[i];
                    if (d_arr[i] == 0){
                        c++;
                    }
                } 
                break;
            }
    }
    cout << "sum between zeros = " << sum << endl;
    int t = 0;
    for (int k = 0; k < size; k++){
        for (int i = 1; i < size; i++){
            if (d_arr[i] < 0 && d_arr[i-1] >= 0){
                swap (d_arr[i], d_arr[i - 1]);
            }
        }
    }
    for (int i = 0; i < size; i++){
        cout << d_arr[i] << " ";
    }   
        
    
    delete[]d_arr;
}