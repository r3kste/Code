#include <bits/stdc++.h>
using namespace std;

int main() {
    int t = 0;
    cin >> t;
    string o = "";

    for (int i = 0; i < t; i++) {
        int n = 0;
        cin >> n;
        vector<int> a;

        for (int j = 0; j < n; j++) {
            int temp = 0;
            cin >> temp;
            a.push_back (temp);
        }

        if (a[1] == a[2] && a[1] != a[0]) {
            o.append ("1\n");
        } else {
            for (int j = 0; j < n - 1; j++) {
                if (a[j] != a[j + 1]) {
                    o.append (to_string (j + 2) + "\n");
                    break;
                }
            }
        }

        a.clear();
    }

    cout << o;
    return 0;
}