#include <bits/stdc++.h>
using namespace std;

int main() {
    long arr[4];
    int mx = 0;

    for (int i = 0; i < 4; i++) {
        cin >> arr[i];

        if (arr[i] > arr[mx]) {
            mx = i;
        }
    }

    for (int i = 3; i > -1; i--) {
        if (i == mx) {
            continue;
        }

        cout << arr[mx] - arr[i] << " ";
    }

    return 0;
}
