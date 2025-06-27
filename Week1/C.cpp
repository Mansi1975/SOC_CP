#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    int y;
    cout  << endl;
    cin >> y;

    y += 1;
    bool found = false;
    

   
 do{
    string numstr = to_string(y);
    int size = numstr.length();
    found = true;
    

    for(int i=0; i<size; i++){
        for(int j = i+1; j<size; j++){
            if(numstr[i] == numstr[j]){
                found = false;
                break;
            } 
        }
        if(!found){
            break;
        }
    }

if(found){
    cout << y << endl;
}
 y++;
 } while(!found);



    return 0;
}
