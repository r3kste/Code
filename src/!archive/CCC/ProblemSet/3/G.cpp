#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 0, s = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int p = 0, q = 0;
        cin >> p >> q;

        if (q > p + 1) {
            s++;
        }
    }

    cout << s << endl;
    return 0;
}