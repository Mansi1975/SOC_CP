#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

void solveTestCase(int n, int m, int k, const string &a) {
    vector<bool> visited(n + 2, false); 
    queue<pair<int, int>> q; 
    q.push({0, 0}); 
    visited[0] = true;

    while (!q.empty()) {
        auto [pos, water] = q.front(); q.pop();

        if (pos == n + 1) {
            cout << "YES\n";
            return;
        }

        if (pos == 0 || (pos >= 1 && a[pos - 1] == 'L')) {
            
            for (int j = 1; j <= m; ++j) {
                int next = pos + j;
                if (next > n + 1) break;

                if (next == n + 1 || a[next - 1] != 'C') {
                    if (!visited[next]) {
                        visited[next] = true;
                        q.push({next, water});
                    }
                }
            }
        } else if (pos >= 1 && a[pos - 1] == 'W') {
           
            int next = pos + 1;
            if (next <= n + 1 && (next == n + 1 || a[next - 1] != 'C')) {
                if (!visited[next] && water + 1 <= k) {
                    visited[next] = true;
                    q.push({next, water + 1});
                }
            }
        }
    }

    cout << "NO\n";
}

int main() {
    int t;
    cin >> t;

    for (int test = 0; test < t; ++test) {
        int n, m, k;
        cin >> n >> m >> k;
        string s;
        cin >> s;
        solveTestCase(n, m, k, s);
    }

    return 0;
}
