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

int solve()
{
    fastio;
    int n, x;
    cin >> n >> x;
    vi a (n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    //f(x) = no of distinct ways to get a sum of x
    //ans = f(x)
    //f(x) = sigma(f(x-c_i))
    ll dp[1000000];

    for (int i = 0; i < x + 1; i++)
    {
        dp[i] = 0;
    }

    dp[0] = 1;

    for (int i = 1; i < x + 1; i++)
    {
        for (auto j : a)
        {
            if (i >= j)
            {
                dp[i] += (dp [i - j]);
                dp[i] %= MOD;
            }
        }
    }

    cout << dp[x] % MOD;
    return 0;
}

int main()
{
    fastio;
    int t = 1;
    
    while (t--)
    {
        solve();
        cout << "\n";
    }
}