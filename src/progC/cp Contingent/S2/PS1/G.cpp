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
    ll n, c = 0;
    cin >> n;
    vll inp (n + 1);
    vll ps (n + 1, 0);
    vector<pair<ll, ll>> neg;

    for (int i = 0; i < n; i++) {
        cin >> inp[i];

        if (inp[i] >= 0) {
            ps[i + 1] = ps[i] + inp[i];
            c++;
        } else {
            neg.pb (mp (inp[i], i));
            ps[i + 1] = ps[i];
        }
    }

    sort (rall (neg));

    for (int i = 0; i < neg.size(); i++) { //go through the neg elements
        bool flag = true;

        for (int j = neg[i].S; j < n; j++) {
            if (ps[j + 1] + neg[i].F < 0) {
                flag = false;
                break; // break and end once a negative element is more negative than the current sum
            }
        }

        if (flag) {
            c++;

            for (int j = neg[i].S; j < n; j++) { //update the prefix sums
                ps[j + 1] += neg[i].F;
            }
        }
    }

    cout << c;
    return 0;
}

int main() {
    fastio;
    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
        cout << "\n";
    }
}
