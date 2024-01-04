#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    long a[t];

    for (int i = 0; i < t; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < t; i++) {
        cout << int (ceil (a[i] / 2.0) - 1) << endl;
    }

    return 0;
}