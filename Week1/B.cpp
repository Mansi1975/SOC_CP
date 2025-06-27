#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main(){

    int n;

    cin >> n; 
    
    int sum;
     string fin;
     bool found = false;
    
    for(int a=0; a<=(n/4); a++){
        for(int b=0; b<=(n/7); b++){
            sum = 4*a + 7*b;
            if(n == sum){
                
                string temp = string(a, '4') + string(b, '7');
                
                if (!found || temp.length() < fin.length() || (temp.length() == fin.length() && temp < fin)) {
                    fin = temp;
                    found = true;
                }
            } 
        }
    }

  if(found){
     cout << fin << endl;
  } else{
    cout << "-1" << endl;
  }
  




    return 0;
}