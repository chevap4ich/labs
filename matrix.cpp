#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void print_vector(vector<vector<int>>& v){
    for (int i = 0; i < v.size(); i++){
        for (int j = 0; j < v[i].size(); j++){
            cout << v[i][j] << "\t";
        }
        cout << endl;
    }
}

double min_avg_low_d(vector<vector<int>>& v){
    int n = v.size();
    double maxLow = 0;
    for (int i = n - 2; i > 0; i -= 1){
        double summa = 0;
        double avg;
        int j = n - 1;
        int u = i;
        for (int k = 0; k < n - i; k++){
            summa = summa + v[u][j];
            u += 1;
            j -= 1;
        }
        avg = summa / (n - i);
        if (abs(avg) > maxLow && maxLow == 0){ 
            maxLow = avg;
        }
        if (avg < maxLow){
            maxLow = avg;
        }
    }
    return maxLow;

}
double min_avg_high_d(vector<vector<int>>& v){
    int n = v.size();
    double maxHigh = 0;
    for (int i = 1; i < n - 1; i++){
        double summa = 0;
        double avg;
        int u = i;
        
        for (int j = 0; j < i + 1; j++){
            summa = summa + v[u][j];
            u -= 1;
        }
        avg = summa / (i + 1);
        if (abs(avg) > maxHigh && maxHigh == 0){ 
            maxHigh = avg;
        }
        if (avg < maxHigh){
            maxHigh = avg;
        }
        
    }
    return maxHigh;
}

int main(){
    int n = 0;
    cout << "size of matrix(max 10) - ";
    cin >> n;
    if (n >=10){
        cout << "wrong size";
        return 0;
    }
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < matrix.size(); i++){
        int j = i;
        for (j; j < matrix.size(); j++){
            cout << "enter the element [" << i << "][" << j << "]";
            cin >> matrix[i][j];
            matrix[j][i] = matrix[i][j];
        }
    }   
    print_vector(matrix);
    for (int j = 0; j < n; j++){
        int max = matrix[0][j];
        bool tf = true;
        for (int i = 0; i < n; i++){
            if (matrix[i][j] > 0){
                tf = false;
                break;
            }
            if (matrix[i][j] > max){
                max = matrix[i][j];
            }
        }
        if (tf){
            cout << max << "\t";
        }
        else{
            cout << " " << "\t";
        }
    }   
    if (min_avg_high_d(matrix) < min_avg_low_d(matrix) && matrix.size() > 2){
        cout << endl << "min avg = " << min_avg_high_d(matrix);
    }
    if (min_avg_high_d(matrix) > min_avg_low_d(matrix) && matrix.size() > 2){
        cout << endl << "min avg = " << min_avg_low_d(matrix);
    }
    if (matrix.size() < 3){
        cout << endl << "There are no diagonals parallel to the secondary diagonal";
    }
}