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

int n;
vector<vector<int>> adj;
vector<bool> visited;
vii dp;
vector<bool> dpd;
int solve()
{
    fastio;
    cin >> n;
    adj = vector<vi> (n);
    visited = vector<bool> (n, false);
    dp = vii (n);
    dpd = vector<bool> (n);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb (v);
        adj[v].pb (u);
    }

    return 0;
}

int main()
{
    fastio;
    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
        cout << "\n";
    }
}