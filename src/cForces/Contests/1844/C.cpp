#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        bool flag = false;
        long long a = 0, b = 0;
        long mx = 0;

        for (int i = 0; i < n; i++) {
            long temp = 0;
            cin >> temp;

            if (i == 0) {
                mx = temp;
            }

            if (temp >= 0) {
                flag = true;

                if (i % 2 == 0) {
                    a += temp;
                } else {
                    b += temp;
                }
            }

            if (temp > mx) {
                mx = temp;
            }
        }

        if (!flag) {
            cout << mx << endl;
        } else {
            cout << ((a > b) ? a : b) << endl;
        }
    }

    return 0;
}