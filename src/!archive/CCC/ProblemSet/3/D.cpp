#include <bits/stdc++.h>
using namespace std;

int main() {
    int t = 0;
    cin >> t;
    string a = "", o = "";

    for (int i = 0; i < t; i++) {
        a = "";
        int n = 0;
        cin >> n;

        for (int k = 0; k < 2 * (n - 1); k++) {
            string temp = "";
            cin >> temp;

            if (temp.length() == n - 1) {
                a.append (temp);
            }
        }

        string b = a;
        reverse (a.begin(), a.end());
        o.append ((a == b) ? "YES\n" : "NO\n");
    }

    cout << o;
    return 0;
}