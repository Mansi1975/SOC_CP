#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n;
    cout << endl;
    cin >> n;
    int i = 0;

    vector<int> p(n);
    vector<int> q(n);

    for(int i=0; i<n; i++){
        cin >> p[i] >> q[i];

    }

    
    int sum = 0;

    //Checking for rooms availability
    for(int i=0; i<n; i++){
         if((q[i] - p[i]) >= 2){
        sum ++;
    } 
    }
    cout << sum << endl;
   
    
    return 0;
}