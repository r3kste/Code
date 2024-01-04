#include <bits/stdc++.h>
using namespace std;

int main() {
    int t = 0;
    cin >> t;
    string o = "";

    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        o.append ((a > 1 && b > 1) ? "1" : to_string (a + b)).append ("\n");
    }

    cout << o;
    return 0;
}