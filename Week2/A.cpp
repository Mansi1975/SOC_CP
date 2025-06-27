#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int t;
    cin >>t;

    while(t>0){
        t--;
        int n;
        cin >> n;

        vector<int> a(2*n);
        for(int i=0; i<2*n; i++){
            cin >> a[i];
        }
    
        sort(a.begin(), a.end());

        int x_min = a[0];
        int x_max = a[n-1];
        int y_min = a[n];
        int y_max = a[2* n-1];
        int s = (x_max - x_min) + (y_max - y_min);

        cout << s << endl;

        for(int i=0; i<n; i++){
            cout << a[i] << " " << a[i+n] << endl;
        }



    }



    return 0;
}