#include <iostream>
#include <string>
#include <cctype>
using namespace std;


int main(){

    string s1;
    string s2;

   
    cin >> s1;
    '\n';
    
    cin >> s2;

    for (int i = 0; i < s1.length(); i++) {
        s1[i] = tolower(s1[i]);
        s2[i] = tolower(s2[i]);
    }

    if(s1 < s2){
        cout << "-1" << '\n';
    } else if(s1 > s2){
        cout << "1" << '\n';
    } else {
        cout << "0" << '\n';
    }

    return 0;
}