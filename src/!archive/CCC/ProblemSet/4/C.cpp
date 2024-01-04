#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    int flag = 0, c = 0;
    cin >> n >> k;
    vector<int> a;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a.push_back (temp);

        if (i == k - 1) {
            flag = a[i];
        }
    }

    for (int i = 0; i < n; i++)
        if (a[i] > 0 && a[i] >= flag) {
            c++;
        }

    cout << c << endl;
    return 0;
}