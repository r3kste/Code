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
    int n;
    cin >> n;
    vi a (n);
    vi b (n);
    vi c;
    vi d;
    to (i, 0, n, i + 1)
    {
        cin >> a[i];
        cin >> b[i];
    }
    to (i, 0, n, i + 1)
    {
        to (j, 0, n, j + 1)
        {
            if (i != j)
            {
                c.push_back ((a[i] + a[j]) / 2);
                d.push_back ((b[i] + b[j]) / 2);
            }
        }
    }
    return 0;
}