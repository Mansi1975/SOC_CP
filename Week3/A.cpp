#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int test = 0; test < t; ++test) {
        int n;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int minVal = 1, maxVal = n;
        int minIdx = 0, maxIdx = 0;

        for (int i = 0; i < n; ++i) {
            if (a[i] == minVal) minIdx = i;
            if (a[i] == maxVal) maxIdx = i;
        }

        if (minIdx > maxIdx) swap(minIdx, maxIdx);

       
        int op1 = maxIdx + 1;
       
        int op2 = n - minIdx;
        
        int op3 = (minIdx + 1) + (n - maxIdx);

        cout << min({op1, op2, op3}) << "\n";
    }

    return 0;
}
