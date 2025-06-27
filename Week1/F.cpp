#include <iostream>
using namespace std;

int main(){

    int n;
    string col;

    //cout << "Enter numbe rof stones on table: " << '\n';
    cin >> n;

    //cout << "Enter their colors: " << '\n';
    cin >> col;

    int c = 0;

    for(int i=0; i<n; i++ ){
        if(col[i] == col[i-1]){
            c+=1;
        } else{
            c+=0;
        }
    }

cout << c << endl;


    return 0;
}