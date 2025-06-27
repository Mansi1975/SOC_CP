#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int minutes = 0;

    while (a > 0 && b > 0) {
        
        if ((a == 1 && b <= 2) || (b == 1 && a <= 2)) break;

       
        if (a < b) {
            a += 1;
            b -= 2;
        } else {
            b += 1;
            a -= 2;
        }

        minutes++;
    }

    cout << minutes << endl;
    return 0;
}
