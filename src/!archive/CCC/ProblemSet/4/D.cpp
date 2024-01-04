#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    string o = "";

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> a;

        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            a.push_back (temp);
        }

        sort (a.begin(), a.end());
        long long p = (long long)a[a.size() - 1] * (long long)a[a.size() - 2];
        long long q = (long long)a[0] * (long long)a[1];
        cout << ((p > q) ? p : q) << endl;
        a.clear();
    }

    return 0;
}