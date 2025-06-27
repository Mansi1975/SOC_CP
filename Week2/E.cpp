#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getMaxRemovals(const vector<int>& sorted, int initialScore) {
    long long score = initialScore;
    int count = 0;
    for (int x : sorted) {
        if (score >= x) {
            score += x;
            count++;
        } else {
            break;
        }
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;

        vector<int> sortedAll = a;
        sort(sortedAll.begin(), sortedAll.end());

        for (int i = 0; i < n; ++i) {
            vector<int> sortedRest;
            bool removed = false;
            for (int x : sortedAll) {
                if (x == a[i] && !removed) {
                    removed = true;
                    continue;
                }
                sortedRest.push_back(x);
            }

            int res = getMaxRemovals(sortedRest, a[i]);
            cout << res << " ";
        }
        cout << '\n';
    }
    return 0;
}
