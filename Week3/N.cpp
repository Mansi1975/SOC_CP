#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);  
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int max_len = 1;
    int current_len = 1;

    for (int i = 1; i < n; ++i) {
        if (a[i] <= 2 * a[i - 1]) {
            current_len++;
        } else {
            current_len = 1;
        }
        if (current_len > max_len) {
            max_len = current_len;
        }
    }

    cout << max_len << endl;
    return 0;
}
