#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char str[100];
    char min_word[100];
    int min_chars = 100;
    cout << "Enter string" << endl;
    cin.getline(str, 100);
    char* word = strtok(str, " ");
    while (word != 0){
        int count = 0;
        char* un_chars = new char[256];
        memset(un_chars, 0, 256);
        for (int i = 0; i < strlen(word); i++){
            if (!un_chars[(int)word[i]]){
                un_chars[(int)word[i]] = 1;
                count++;
            }
        }
        if (count < min_chars){
            min_chars = count;
            strcpy(min_word, word);
        }
        delete[]un_chars;
        word = strtok(0, " ");
    }
    cout << "The word with minimum of unique symbols: " << min_word;
}