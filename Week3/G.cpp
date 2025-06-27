#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(int n, int x, vector<int>& a) {
    sort(a.rbegin(), a.rend()); 
    
    int teams = 0, team_size = 0;

    for (int i = 0; i < n; ++i) {
        team_size++;
        if (team_size * a[i] >= x) {
            teams++;
            team_size = 0; 
        }
    }
    cout << teams << '\n';
}

int main() {
    int t;
    cin >> t;

    for (int test = 0; test < t; ++test) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        solve(n, x, a);
    }

    return 0;
}
