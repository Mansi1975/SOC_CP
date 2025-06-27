#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> res;
    int sum = 0;
    for (int i = 1; sum + i <= n; ++i) {
        res.push_back(i);
        sum += i;
    }
    if (sum < n) {
        res.back() += n - sum;
    }
    cout << res.size() << "\n";
    for (int val : res) cout << val << " ";
    cout << "\n";
    return 0;
}
