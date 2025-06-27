#include <iostream>
#include <string>
using namespace std;

int countMismatches(const string& s, const string& pattern) {
    int mismatches = 0;
    int n = s.size(), k = pattern.size();
    for (int i = 0; i < n; ++i) {
        if (s[i] != pattern[i % k]) {
            mismatches++;
            if (mismatches > 1) return mismatches;
        }
    }
    return mismatches;
}

int main() {
    int t;
    cin >> t;
    
    for (int test = 0; test < t; ++test) {
        int n;
        string s;
        cin >> n >> s;

        int result = n;
        for (int len = 1; len <= n; ++len) {
            string pattern = s.substr(0, len);
            int mismatches = countMismatches(s, pattern);
            if (mismatches <= 1) {
                result = len;
                break;
            }
        }
        cout << result << '\n';
    }

    return 0;
}
