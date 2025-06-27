#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int n, t;
    cin >> n >> t;

    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    queue<int> q;
    int c=0;


    for(int i=0; i<n; i++){
        q.push(a[i]);
        c += a[i];

        if(c > t && !q.empty()){
            c -= q.front();
            q.pop();
        }
    }

cout << (int)q.size() << endl;

    return 0;
}