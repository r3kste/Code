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

bool is_beautiful (vi a) {
    int n = a.size();

    for (int i = 0; true;) {
        if (i == n) {
            return true;
        } else if (i > n) {
            return false;
        } else {
            i += (a[i] + 1);
        }
    }
}

ll f (vi a) {
    if (is_beautiful (a)) {
        return 0;
    } else {
        int n = a.size();
        ll sum = n;

        for (int i = 0; i < n; i++) {
            auto b = a;

            if (b[0] > n) {
                sum = n;
                break;
            }

            b.erase (b.begin() + i);
            sum = min (sum, 1 + f (b));
        }

        return sum;
    }
}

int solve() {
    fastio;
    int n;
    cin >> n;
    vi a (n);
    vi dp (n, -1);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    //f(vector) = min no of operations to make it beautiful
    //ans = f(a)
    //f(vector)= sigma(f(vector.remove all elements one by one))
    // cout << f (a);
    //g(x) = min no of operation to make elements from x to n beautiful
    //ans = f(0)
    // 3 4 5 2 6 1
    //g(x) = (i+a[i]+1==n)? 0: (i+a[i]+1>n) ? (1+g(x+1)):(min(1+g(x+1),(g(i+a[i]+1))));
    dp[n - 1] = 1;

    for (int i = n - 2; i > -1; i--) {
        dp[i] = (i + a[i] + 1 == n) ? 0 : (i + a[i] + 1 > n) ? (1 + dp [i + 1]) : (min (1 + dp [ (i + 1)], (dp [ (i + a[i] + 1)])));
    }

    cout << dp[0];
    dp.clear();
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