#include <iostream>
#include <string>
using namespace std;

void solveTestCase(string &s) {
    int n = s.length();

    // First pass: Find a known character and fill left/right from there
    for (int i = 0; i < n; ++i) {
        if (s[i] != '?') {
            // Fill left
            for (int j = i - 1; j >= 0; --j) {
                if (s[j] == '?') {
                    s[j] = (s[j + 1] == 'R') ? 'B' : 'R';
                } else break;
            }
            // Fill right
            for (int j = i + 1; j < n; ++j) {
                if (s[j] == '?') {
                    s[j] = (s[j - 1] == 'R') ? 'B' : 'R';
                } else break;
            }
            break;  // Only need to start from one known character
        }
    }

    // If all were '?', start from 'B' and alternate
    if (s[0] == '?') {
        s[0] = 'B';
        for (int i = 1; i < n; ++i) {
            s[i] = (s[i - 1] == 'R') ? 'B' : 'R';
        }
    }

    cout << s << '\n';
}

int main() {
    int t;
    cin >> t;

    for (int test = 0; test < t; ++test) {
        int n;
        string s;
        cin >> n >> s;
        solveTestCase(s);
    }

    return 0;
}
