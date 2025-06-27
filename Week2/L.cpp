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
        vector<int> c(n);
        for (int i = 0; i < n; ++i) {
            cin >> c[i];
        }

        sort(c.begin(), c.end());

        if (c[0] != 1) {
            cout << "NO\n";
            continue;
        }

        long long sum = 1;
        bool ok = true;

        for (int i = 1; i < n; ++i) {
            if (c[i] > sum) {
                ok = false;
                break;
            }
            sum += c[i];
        }

        cout << (ok ? "YES" : "NO") << "\n";
    }

    return 0;
}
