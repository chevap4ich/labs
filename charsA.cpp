#include <iostream>
using namespace std;
char* str_cat(char* strDestination, const char* strSource){
    int k = 0;
    int strDestinationLen = 0;
    int strSourceLen = 0;
    for (int i = 0; strDestination[i] != 0; i++){
        strDestinationLen++;
    }
    for (int i = 0; strSource[i] != 0; i++){
        strSourceLen++;
    }
    for (int i = strDestinationLen; i < strDestinationLen + strSourceLen; i++){
        strDestination[i] = strSource[k];
        k++;
    }
    return strDestination;
}
int main(){
    char str[5] = "abcd";
    char str1[100] = "abcdefghi";
    char* str_p {str};
    char* str_p1 {str1};
    cout << str_cat(str_p1, str_p);
}