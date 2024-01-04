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
    int n;
    cin >> n;
    vi a (n);
    vi deck;
    ll pow = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // for (int i = 0; i < n; i++)
    // {
    //     int temp;
    //     cin >> temp;

    //     if (temp > 0)
    //     {
    //         if (c > 0)
    //         {
    //             a.pb (-c);
    //         }

    //         a.pb (temp);
    //         c = 0;
    //     }
    //     else if (temp == 0)
    //     {
    //         c++;
    //     }
    // }

    // if (c > 0)
    // {
    //     a.pb (-c);
    // }

    for (int i = 0; i < n; i++) {
        int temp = a[i];

        if (temp > 0) {
            deck.pb (temp);
        } else {
            sort (all (deck));

            if (deck.size() >= 1) {
                pow += deck[deck.size() - 1];
                deck[deck.size() - 1] = 0;
            }

            // int j;
            // for (j = i; j < n - 1; j++)
            // {
            //     if (a[j + 1] != 0)
            //     {
            //         break;
            //     }
            // }
            // int num = j - i + 1;
            // for (j = deck.size() - 1; j > max (-1, (int) (deck.size()) - 1 - num); j--)
            // {
            //     pow += deck[j];
            //     deck[j] = 0;
            // }
            // deck.clear();
        }
    }

    cout << pow;
    return 0;
}

int main() {
    fastio;
    int t = 1;
    cin >> t;

    while (t--) {
        solve();
        cout << "\n";
    }
}