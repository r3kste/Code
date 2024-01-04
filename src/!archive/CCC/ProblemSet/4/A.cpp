#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    string o = "";

    for (int i = 0; i < t; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        int sum = a + b + c;
        int mx = max (a, max (b, c));
        int mn = min (a, min (b, c));
        o.append (to_string (sum - mx - mn) + "\n");
    }

    cout << o;
    return 0;
}