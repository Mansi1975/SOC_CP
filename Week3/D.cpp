#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int maxCoins(const string& s) {
    int n = s.length();
    vector<int> dp(n, -1);  

    dp[0] = 0; 

    for (int i = 1; i < n; ++i) {
        if (s[i] == '*') continue; 

        int best = -1;
        if (i - 1 >= 0 && dp[i - 1] != -1)
            best = max(best, dp[i - 1]);
        if (i - 2 >= 0 && dp[i - 2] != -1)
            best = max(best, dp[i - 2]);

        if (best != -1)
            dp[i] = best + (s[i] == '@' ? 1 : 0);
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    int t;
    cin >> t;

    for (int test = 0; test < t; ++test) {
        int n;
        string s;
        cin >> n >> s;
        cout << maxCoins(s) << '\n';
    }

    return 0;
}
