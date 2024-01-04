#include <iostream>
using namespace std;
int main() {
    long t, n, s, m, a;
    cin >> t;

    while (t--) {
        cin >> n;
        s = m = 0;

        while (n--) {
            cin >> a;
            s += a;
            m = (a > m) ? a : m;
        }

        cout << ((m > s / 2 || s % 2) ? "YES\n" : "NO\n");
    }
}