#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> route(n);
        unordered_map<int, int> first, last;

        for (int i = 0; i < n; ++i) {
            cin >> route[i];
            if (first.count(route[i]) == 0) {
                first[route[i]] = i;
            }
            last[route[i]] = i;
        }

        for (int q = 0; q < k; ++q) {
            int a, b;
            cin >> a >> b;

            if (first.count(a) && last.count(b) && first[a] <= last[b]) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}
