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
bool isPrime (int n)
{
    if (n < 2)
    {
        return false;
    }

    if (n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || n == 13 || n == 17 || n == 19 || n == 23)
    {
        return true;
    }

    if (nmod (2) || nmod (3) || nmod (5) || nmod (7) || nmod (11) || nmod (13) || nmod (17) || nmod (19) || nmod (23))
    {
        return false;
    }

    to (i, 23, sqrt (n) + 1, 6) if (n % i == 0 || n % (i + 2) == 0)
    {
        return false;
    }

    return true;
}

int solve()
{
    fastio;
    ll n, m, x, k;
    cin >> n >> m >> x >> k;
    x = x % k;
    vi b (n + m);
    bool flag = true;
    string out = "";
    to (i, 0, n + m, i + 1)
    {
        cin >> b[i];
    }
    ll cn = n, cm = m;
    to (i, 0, cn + cm, i + 1)
    {
        ll a = pow (x, i + 1);
        a = a % k;
        a = a + 1;
        ll o = (ll)ceil ((double)b[i] / (double)a);

        if (isPrime (o))
        {
            m--;
        }
        else
        {
            n--;
        }

        if (m == 0)
        {
            out = "Chahel";
            flag = false;
        }

        if (n == 0)
        {
            out = "Shaun";
            flag = false;
        }
    }

    if (flag)
    {
        if (n == m)
        {
            out = "-1";
        }

        if (n < m)
        {
            out = "Shaun";
        }

        if (m > n)
        {
            out = "Chahel";
        }
    }

    cout << out;
    return 0;
}