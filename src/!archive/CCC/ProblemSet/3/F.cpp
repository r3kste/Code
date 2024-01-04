#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 0, h = 0, s = 0;
    cin >> n >> h;

    for (int i = 0; i < n; i++) {
        int a = 0;
        cin >> a;
        s += ((a <= h) ? 1 : 2);
    }

    cout << s << endl;
    return 0;
}