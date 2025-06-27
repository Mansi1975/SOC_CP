#include <iostream>
#include <string>
using namespace std;

int minOperations(string s) {
    int ops = 0;
    bool flipped = false;

    for (int i = 0; i + 1 < s.size(); ++i) {
        char curr = s[i], next = s[i + 1];
        if (flipped) {
            curr = (curr == '0' ? '1' : '0');
            next = (next == '0' ? '1' : '0');
        }

        if (curr == '1' && next == '0') {
            ops++;
            flipped = !flipped;
        }
    }

    return ops;
}

int main() {
    int t;
    cin >> t;

    for (int test = 0; test < t; ++test) {
        int n;
        string s;
        cin >> n >> s;
        cout << minOperations(s) << '\n';
    }

    return 0;
}
