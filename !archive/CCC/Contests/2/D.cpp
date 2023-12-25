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

    if (false)
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
    int n, k;
    cin >> n >> k;
    vi a (n);
    vi ps (n + 1);
    int max = 0;
    map<int, int> mp;
    to (i, 0, n, i + 1)
    {
        ll temp;
        cin >> temp;
        a[i] = temp;
        ps[i + 1] = (ps[i] + a[i]) % k;
    }

    for (int i = 0; i < n + 1; i++)
    {
        int temp = ps[i];

        for (int j = 0; j < n + 1; j++)
        {
            if (ps[j] == temp)
            {
                if ((j - i) > max)
                {
                    max = j - i;
                }
            }
        }
    }

    cout << max;
    return 0;
}