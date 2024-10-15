#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
vector<string> sort_vector(vector<string>& v);
int main(){
    string file1;
    cout << "enter the name of the first file" << endl;
    cin >> file1;
    string file2;
    cout << "enter the name of the second one" << endl;
    cin >> file2;
    int show;
    cout << "Show files contains(1) or no(0)" << endl;
    cin >> show;
    if (show == 1){
        ifstream fin1(file1);
        ifstream fin2(file2);
        vector<string> showStrings;
        string showLine;
        while (getline(fin1, showLine)){
            showStrings.push_back(showLine);
        }
        if (showStrings.size() != 0){
            cout << file1 << ":" << endl;
            for (int i = 0; i < showStrings.size(); i++){
                cout << showStrings[i] << endl;
            }
        }
        showStrings.clear();
        while (getline(fin2, showLine)){
            showStrings.push_back(showLine);
        }
        if (showStrings.size() != 0){
            cout << file2 << ":" << endl;
            for (int i = 0; i < showStrings.size(); i++){
                cout << showStrings[i] << endl;
            }
        }
        showStrings.clear();
        fin1.close();
        fin2.close();
    }
    ifstream fin1(file1);
    ifstream fin2(file2);
    string line;
    vector<string> strings;
    while (getline(fin1, line)){
            strings.push_back(line);
    }
    if (strings.size() == 0){
            cout << "The first file is empty or don't exist in current folder" << endl;
        }
    int h = 0;
    while (getline(fin2, line)){
            strings.push_back(line);
            h += 1;
    }
    if (h == 0){
            cout << "The second file is empty or don't exist in current forder" << endl;
        }
    fin1.close();
    fin2.close();
    sort_vector(strings);
    ofstream fout3("file3");
    for (int i = 0; i < strings.size(); i++){
        fout3 << strings[i] << endl;
    }
    fout3.close();
}
vector<string> sort_vector(vector<string>& v){
    for (int i = 0; i < v.size(); i++){
        for (int i = 1; i < v.size(); i++){
            if (v[i] < v[i - 1]){
                swap(v[i], v[i - 1]);
            }
        }
    }
    return v;
}