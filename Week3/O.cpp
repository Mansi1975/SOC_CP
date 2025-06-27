#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int test_case = 0; test_case < t; ++test_case) {
        int n;
        cin >> n;

        vector<int> a(n);
        unordered_map<int, int> freq;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            freq[a[i]]++;
        }

        bool valid = true;
        for (const auto& entry : freq) {
            if (entry.second > 2) {
                valid = false;
                break;
            }
        }

        cout << (valid ? "YES" : "NO") << endl;
    }

    return 0;
}
