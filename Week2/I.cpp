#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
       vector<long long> transformed(n);

        for (int i = 0; i < n; ++i) {
            long long a;
            cin >> a;
            transformed[i] = a + i + 1; // simulate a[i] + p[i] (p[i] = i+1 for identity permutation)
        }

       sort(transformed.begin(), transformed.end());

        int maxLen = 0;
        int left = 0;
        unordered_set<long long> seen;

        for (int right = 0; right < n; ++right) {
            while (seen.count(transformed[right]) || transformed[right] - transformed[left] > n - 1) {
                seen.erase(transformed[left]);
                ++left;
            }
            seen.insert(transformed[right]);
            maxLen = std::max(maxLen, right - left + 1);
        }

        cout << maxLen << "\n";
    }

    return 0;
}
