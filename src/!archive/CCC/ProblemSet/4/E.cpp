#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, flag, c = 0;
        cin >> n;
        vector<int> a;

        for (int j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            a.push_back (temp);
        }

        sort (a.begin(), a.end());

        for (int j = 0; j < n; j++)
            if (a[j] > a[0]) {
                c++;
            }

        cout << c << endl;
        a.clear();
    }

    return 0;
}