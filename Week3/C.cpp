#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int g(int l, int r, int v, const vector<int>& a) {
    if (l > r) {
        return 0;
    }
    int len = r - l + 1;
    if (len == 1) {
        return (a[l] <= v) ? 1 : 0;
    }
    int pprev = (a[l] <= v) ? 1 : 0;
    int prev = max(pprev, (a[l+1] <= v ? 1 : 0));
    if (len == 2) {
        return prev;
    }
    for (int i = l+2; i <= r; i++) {
        int take = (a[i] <= v) ? 1 : 0;
        int curr = max(prev, pprev + take);
        pprev = prev;
        prev = curr;
    }
    return prev;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        map<int, vector<int>> occ;
        for (int i = 0; i < n; i++) {
            occ[a[i]].push_back(i);
        }

        int ans = 0;
        for (auto& p : occ) {
            int v = p.first;
            vector<int>& indices = p.second;
            int best_total = -1;
            for (int j : indices) {
                int left_seg = 0;
                if (j - 2 >= 0) {
                    left_seg = g(0, j - 2, v, a);
                }
                int right_seg = 0;
                if (j + 2 < n) {
                    right_seg = g(j + 2, n - 1, v, a);
                }
                int total = 1 + left_seg + right_seg;
                if (total > best_total) {
                    best_total = total;
                }
            }
            int candidate = v + best_total;
            if (candidate > ans) {
                ans = candidate;
            }
        }
        cout << ans << endl;
    }
    return 0;
}