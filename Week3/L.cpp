#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int test = 0; test < t; ++test) {
        int n;
        long long l, r;
        cin >> n >> l >> r;

        vector<long long> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        int count = 0;
        long long sum = 0;
        int start = 0;

        for (int i = 0; i < n; ++i) {
            sum += a[i];

            
            while (start <= i && sum > r) {
                sum -= a[start++];
            }

            
            if (sum >= l && sum <= r) {
                count++;
                sum = 0;
                start = i + 1; 
            }
        }

        cout << count << '\n';
    }

    return 0;
}
