#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int tc = 0; tc < t; ++tc) {
        int n;
        cin >> n;

        string row1, row2;
        cin >> row1 >> row2;

        string answer = "";
        map<pair<int, int>, int> count;
        queue<pair<int, int>> q;

        q.push({0, 0});
        count[{0, 0}] = 1;
        answer += row1[0];

        for (int step = 0; step < n; ++step) {
            char minChar = '2';
            map<pair<int, int>, int> newCount;

            while (!q.empty()) {
                auto [r, c] = q.front(); q.pop();
                int ways = count[{r, c}];

               
                if (c + 1 < n) {
                    int nr = r, nc = c + 1;
                    char ch = (nr == 0 ? row1[nc] : row2[nc]);

                    if (ch < minChar) {
                        minChar = ch;
                        newCount.clear();
                        newCount[{nr, nc}] = ways;
                    } else if (ch == minChar) {
                        newCount[{nr, nc}] += ways;
                    }
                }

              
                if (r == 0) {
                    int nr = 1, nc = c;
                    char ch = row2[nc];

                    if (ch < minChar) {
                        minChar = ch;
                        newCount.clear();
                        newCount[{nr, nc}] = ways;
                    } else if (ch == minChar) {
                        newCount[{nr, nc}] += ways;
                    }
                }
            }

            answer += minChar;

          
            queue<pair<int, int>> empty;
            swap(q, empty);
            for (auto &p : newCount) {
                q.push(p.first);
            }
            count = newCount;
        }

        long long totalPaths = 0;
        for (auto &[_, cnt] : count) {
            totalPaths += cnt;
        }

        cout << answer << "\n" << totalPaths << "\n";
    }

    return 0;
}
