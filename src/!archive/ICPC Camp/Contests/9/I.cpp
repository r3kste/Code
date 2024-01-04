#include <bits/stdc++.h>
using namespace std;

#define MOD (LL)(1e9 + 7)
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

#define endl "\n"
#define yesno(a) cout << ((a) ? "Yes" : "No");

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

typedef long long int ll;
typedef unsigned long long int LL;
typedef pair<int, int> ii;

typedef vector<int> vi;
typedef vector<pair<int, int>> vii;
typedef vector<long long int> vll;

int solve() {
    fastio;
    string A, B;
    cin >> A;
    int as = A.size();
    cin >> B;
    int bs = B.size();
    // vector<char> a (n);
    //
    // for (int i = 0; i < as; i++) {
    //     a[i] = A[i];
    // }
    //
    // vector<char> b (n);
    //
    // for (int i = 0; i < bs; i++) {
    //     b[i] = B[i];
    // }
    int ap = 0;
    int bp = 0;
    ll time = 0;

    while (ap < as && bp < bs) {
        if (A[ap] == B[bp]) {
            time++;
            ap++;
            bp++;
        } else {
            if (A[ap] != 'L' && B[bp] != 'L') {
                time++;
                ap++;
                bp++;
            } else {
                if (A[ap] == 'L') {
                    time++;
                    bp++;
                } else {
                    time++;
                    ap++;
                }
            }
        }
    }

    time += (as - ap) + (bs - bp);
    cout << time;
    return 0;
}

int main() {
    fastio;
    int t = 1;

    while (t--) {
        solve();
        cout << "\n";
    }
}
