#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 0, o = 0;
    cin >> n;
    vector<int> a;

    for (int i = 0; i < n; i++) {
        int temp = 0;
        cin >> temp;
        a.push_back (temp);
    }

    for (int i = 0; i < n - 1; i++)
        if (a[i] != a[i + 1]) {
            o++;
        }

    cout << o + 1 << endl;
    return 0;
}