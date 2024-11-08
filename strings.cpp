#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void show_files (string fileName1, string fileName2);
int countLines (string fileName);
void sort_file (string fileName1, string fileName2);

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
        show_files(file1, file2);
    }
    sort_file (file1, file2);
}

void show_files (string fileName1, string fileName2){
    ifstream fin1(fileName1);
        ifstream fin2(fileName2);
        vector<string> showStrings;
        string showLine;
        while (getline(fin1, showLine)){
            showStrings.push_back(showLine);
        }
        if (showStrings.size() != 0){
            cout << fileName1 << ":" << endl;
            for (int i = 0; i < showStrings.size(); i++){
                cout << showStrings[i] << endl;
            }
        }
        showStrings.clear();
        while (getline(fin2, showLine)){
            showStrings.push_back(showLine);
        }
        if (showStrings.size() != 0){
            cout << fileName2 << ":" << endl;
            for (int i = 0; i < showStrings.size(); i++){
                cout << showStrings[i] << endl;
            }
        }
        showStrings.clear();
        fin1.close();
        fin2.close();
}

int countLines (string fileName){
    ifstream fin(fileName);
    int count = 0;
    string line;
    while (getline(fin, line))
    {
        count++;
    }
    fin.close();
    return count;
}

void sort_file (string fileName1, string fileName2){
    ifstream fin1(fileName1);
    ifstream fin2(fileName2);
    ofstream fout3("file3");
    string line1;
    string line2;
    getline(fin1, line1);
    getline(fin2, line2);
    int n1 = 0;
    int n2 = 0;
    for (int i = 0; n1 < countLines(fileName1) && n2 < countLines(fileName2); i++){
        if (line1 == line2){
            fout3 << line1 << endl << line2 << endl;;
            getline(fin1, line1);
            getline(fin2, line2);
            n1++;
            n2++;
            continue;
        }
        if (line1 < line2){
            fout3 << line1 << endl;
            getline(fin1, line1);
            n1++;
            continue;
        }
        if (line1 > line2){
            fout3 << line2 << endl;
            getline(fin2, line2);
            n2++;
            continue;
        }
    }
    if(n1 == countLines(fileName1)){
        fout3 << line2 << endl;
    }
    if(n2 == countLines(fileName2)){
        fout3 << line1 << endl;
    }
    while (getline(fin1, line1)){
        fout3 << line1 << endl;
    }
    while (getline(fin2, line2)){
        fout3 << line2 << endl;
    }
    fin1.close();
    fin2.close();
    fout3.close();
}