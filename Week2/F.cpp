#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    int t;
    cin >> t;
    const double LOG2 = log(2.0);

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        unordered_map<long long, long long> freq;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];

            
            double key = log(a[i]) - a[i] * LOG2;

           
            long long hash_key = round(key * 1e9);

            freq[hash_key]++;
        }

        long long ans = 0;
        for (auto &[_, count] : freq) {
            ans += count * (count - 1) / 2;
        }

        cout << ans << '\n';
    }
    return 0;
}
