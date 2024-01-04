#include <bits/stdc++.h>
using namespace std;

#define to(i, a, b, c) for (int(i) = (a); (i) < b; (i) += c)
#define fro(i, a, b, c) for (int(i) = (b)-1; (i) >= (a); (i) -= c)

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

void solve();

int main() {
    fastio;
    int t = 1;

    if (false) {
        cin >> t;
    }

    while (t--) {
        solve();
        cout << "\n";
    }
}

bool check (int n) {
    string s = to_string (n);
    map<char, int> k;
    int l = s.length();
    to (i, 0, l, 1) {
        k[s[i]]++;

        if (k[s[i]] > 1) {
            return false;
        }
    }
    return true;
}

void solve() {
    fastio;
    int n;
    cin >> n;
    to (i, n + 1, 9877, 1) {
        if (check (i)) {
            cout << i;
            break;
        }
    }
}