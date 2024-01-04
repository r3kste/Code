#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a = 0;
        cin >> a;

        if (a == 1) {
            cout << "HARD" << endl;
            return 0;
        }
    }

    cout << "EASY" << endl;
    return 0;
}