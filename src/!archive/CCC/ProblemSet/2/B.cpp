#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    long a[t][2];

    for (int i = 0; i < t; i++) {
        cin >> a[i][0] >> a[i][1];
    }

    for (int i = 0; i < t; i++) {
        int c = a[i][0];
        int b = a[i][1];
        int r = c % b;

        if (r == 0) {
            cout << 0 << endl;
        } else {
            cout << b - r << endl;
        }
    }

    return 0;
}