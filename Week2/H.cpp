#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int dx[] = {0, 0, 1, -1}; // Right, Left, Down, Up
int dy[] = {1, -1, 0, 0};

int n;

bool isValid(int x, int y) {
    return x >= 0 && x < 2 && y >= 0 && y < n;
}

pair<int, int> arrowMove(char arrow, int x, int y) {
    if (arrow == '>') y += 1;
    else y -= 1;
    return {x, y};
}

bool bfs(const vector<string>& grid) {
    vector<vector<bool>> visited(2, vector<bool>(n, false));
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (!isValid(nx, ny)) continue;

            auto [fx, fy] = arrowMove(grid[nx][ny], nx, ny);
            if (!isValid(fx, fy)) continue;

            if (!visited[fx][fy]) {
                visited[fx][fy] = true;
                q.push({fx, fy});
            }
        }
    }

    return visited[1][n - 1];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<string> grid(2);
        cin >> grid[0] >> grid[1];

        cout << (bfs(grid) ? "YES" : "NO") << '\n';
    }

    return 0;
}
