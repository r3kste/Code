#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<string> v;

    for (int i = 0; i < n; i = i + 1) {
        string a;
        cin >> a;
        v.push_back (a);
    }

    for (int i = 0; i < n; i = i + 1) {
        string a1 = v[i].substr (0, v[i].length() / 2);
        cout << ((v[i] == (a1 + a1)) ? "YES" : "NO") << endl;
    }

    return 0;
}
