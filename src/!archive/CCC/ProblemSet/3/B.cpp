#include <bits/stdc++.h>
using namespace std;

int main() {
    int t = 0;
    cin >> t;
    vector<string> op;

    for (int i = 0; i < t; i++) {
        string a = "";
        cin >> a;
        int l = a.length();

        if (l <= 10) {
            op.push_back (a);
        } else {
            op.push_back (a[0] + to_string (l - 2) + a[l - 1]);
        }
    }

    for (int i = 0; i < t; i++) {
        cout << op[i] << endl;
    }
}