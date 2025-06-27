#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    int totalOnes = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 1) totalOnes++;
    }

    int maxGain = -1e9;  
    int currentGain = 0;

    for (int i = 0; i < n; ++i) {
        
        int val = (a[i] == 0) ? 1 : -1;

        currentGain = max(val, currentGain + val);
        maxGain = max(maxGain, currentGain);
    }

   
    if (totalOnes == n) cout << totalOnes - 1<< endl;
    else cout << totalOnes + maxGain << endl;

    return 0;
}
