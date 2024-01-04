#include <bits/stdc++.h>
using namespace std;

#define nmod(m) n % m == 0

#define MOD (LL)(1e9 + 7)
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

typedef long long int ll;
typedef unsigned long long int LL;
typedef pair<int, int> ii;

typedef vector<int> vi;
typedef vector<long long int> vll;
typedef vector<unsigned long long int> vLL;

int solve();

int main() {
    fastio;
    int t = 1;
    cin >> t;

    while (t--) {
        solve();
        cout << "\n";
    }
}

int solve() {
    fastio;
    ll n, p;
    cin >> n >> p;
    vector<ii> a (n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
    }

    for (int i = 0; i < n; i++) {
        cin >> a[i].second;
    }

    sort (a.begin(), a.end(), [] (ii & a, ii & b) {
        return a.second < b.second;
    });
    // int ptr = -1;
    // int ptr1 = -1;
    // int cost = 0;
    // cost += p;
    // ptr++;
    // for (int rem = n - 1 - ptr; rem > 0; rem = n - 1 - ptr)
    // {
    //     if (a[ptr].first >= rem)
    //     {
    //         cout << rem + a[ptr].second;
    //         ptr = n - 1;
    //     }
    //     else
    //     {
    //         int number = a[ptr].first + ptr;
    //         for (; ptr <= number; ptr++)
    //         {
    //         }
    //     }
    //     ptr1++;
    // }
    int fi;
    ll cost = p;
    ll np = 1;

    for (int i = 0; i < n; i++) {
        // if (np >= n)
        // {
        //     fi = i;
        //     cout << min(n * p, cost);
        //     break;
        // }
        // cost += (min(a[i].first, n - np) * a[i].second);
        // np += a[i].first;
        if (a[i].first > n - np) {
            cost += max ((ll)0, (n - np)) * min (p, (ll)a[i].second);
            break;
        } else {
            cost += a[i].first * min (p, (ll)a[i].second);
            np += a[i].first;
        }
    }

    cout << cost;
    return 0;
}