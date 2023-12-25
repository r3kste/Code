#include <bits/stdc++.h>
using namespace std;

#define nmod(m) n % m == 0

#define to(i, a, b, c) for (int(i) = (a); (i) < (b); (i) = (c))
#define fro(i, a, b, c) for (int(i) = (b)-1; (i) >= (a); (i) = (c))

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

int main()
{
    fastio;
    int t = 1;

    if (true)
    {
        cin >> t;
    }

    while (t--)
    {
        solve();
        cout << "\n";
    }
}

int solve()
{
    fastio;
    int n, m;
    cin >> n >> m;
    vi a (n);
    ll s = 0;
    to (i, 0, n, i + 1)
    {
        cin >> a[i];
    }
    to (i, 0, n, i + 1)
    {
        ll p = 1;

        for (int j = 0; j < m; j++)
        {
            p *= a[i + j];
        }

        s += p;
    }
    cout << s;
    return 0;
}