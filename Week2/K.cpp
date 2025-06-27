#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int test = 0; test < t; ++test) {
        int n;
        cin >> n;
        vector<long long> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

       
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + a[i];
        }

        
        long long maxVal = LLONG_MIN;
        for (int i = 0; i <= n; ++i) {
            long long val = abs(prefix[i]) + (prefix[n] - prefix[i]);
            maxVal = max(maxVal, val);
        }

        cout << maxVal << "\n";
    }

    return 0;
}
