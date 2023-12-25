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
    int n;
    cin >> n;
    vi a (n);
    vll ss (n);
    ll S = 0;
    ll c = 0;
    to (i, 0, n, i + 1)
    {
        cin >> a[i];
        S += a[i];
    }
    ll cS = S;
    to (i, 1, n + 1, i + 1)
    {
        ss[n - i - 1] = ss[n - i] + a[n - i];
    }
    // for (int s = 0; s < (n - 1); s++)
    // {
    //     vll ps(n + 1 - s);
    //     vll ss(n + 1 - s);
    //     int temp = 1;
    //     for (int i = s + 1; temp < n + 1; temp++, i++)
    //     {
    //         ps[temp] = a[i - 1] + ps[temp - 1];
    //     }
    // }
    ll s = 0;

    for (int k = 0; k < n; k++)
    {
        // if (S % 2 == 0)
        //     for (int i = k; i < n; i++)
        //     {
        //         s += a[i];
        //         if (s == S / 2)
        //         {
        //             c++;
        //         }
        //     }
        // s = 0;
        // S -= a[k];
        ll rs = ss[k];

        if (rs > cS / 2)
        {
            continue;
        }

        for (int i = k; i > -1; i--)
        {
            s += a[i];

            if (s > cS / 2)
            {
                break;
            }

            if (s == rs)
            {
                c++;
            }
        }
    }

    // int cn = n - 1;
    // for (int k = a[cn]; cn > -1; k += a[--cn])
    // {
    //     ll s = 0;
    //     for (int p = cn; p > -1; p--)
    //     {
    //     }
    // }
    cout << c;
    return 0;
}