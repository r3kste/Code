#include <bits/stdc++.h>
using namespace std;

string tol (string a) {
    string o = "";

    for (int i = 0; i < a.length(); i++) {
        char c = tolower (a[i]);
        string cc (1, c);
        o.append (cc);
    }

    return o;
}

int main() {
    string a, b;
    cin >> a >> b;
    a = tol (a);
    b = tol (b);

    if (a == b) {
        cout << 0 << endl;
    } else {
        cout << copysign (1, (a.compare (b))) << endl;
    }

    return 0;
}
