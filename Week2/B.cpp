#include <iostream>
#include <vector>
using namespace std;

string Qsort(const vector<int>& a) {
    int n = a.size();
    if (n % 2 == 1) {
        return "YES"; 
    }

    long long sum = 0;
    for (int i = 1; i < n; i += 2) {
        sum += a[i] - a[i - 1];
    }

    if (sum >= 0) return "YES";
    else return "NO";
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

        cout << Qsort(a) << endl;
    }
    return 0;
}
