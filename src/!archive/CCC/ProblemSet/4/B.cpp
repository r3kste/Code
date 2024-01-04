#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a.push_back (temp);
    }

    sort (a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    cout << endl;
    return 0;
}