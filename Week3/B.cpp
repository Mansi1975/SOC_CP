#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int test = 0; test < t; ++test) {
        int n;
        cin >> n;

        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }

        int count = 0;
        for (int i = 1; i < n; ++i) {
            if (p[i] < p[i - 1]) {
                ++count;
            }
        }

        // Each decrease (inversion between adjacent elements) is a flip in parity
        cout << min(count, 2) << '\n';
    }

    return 0;
}
