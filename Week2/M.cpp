#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    for (int test = 0; test < t; ++test) {
        int n;
        cin >> n;

        vector<pair<int, int>> segments(n);
        for (int i = 0; i < n; ++i) {
            cin >> segments[i].first >> segments[i].second;
        }

        
        sort(segments.begin(), segments.end(), [](auto &x, auto &y) {
            return x.second < y.second;
        });

        multiset<int> starts;
        long long greetings = 0;

        for (auto &[a, b] : segments) {
            
            greetings += distance(starts.upper_bound(a), starts.end());
            starts.insert(a);
        }

        cout << greetings << "\n";
    }

    return 0;
}
