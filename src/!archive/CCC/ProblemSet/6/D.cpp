#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b, c) for (int(i) = ((c > 0) ? (a) : (b - 1)); ((c > 0) ? (i < b) : (i > a - 1)); (i) += c)
#define z(i, n) FOR(i, 0, n, 1)
#define zc(i, n, c) FOR(i, 0, n, c)
#define zr(i, a, b) FOR(i, a, b, 1)
#define zrc(i, a, b, c) FOR(i, a, b, c)

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

#define pb push_back

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

void solve (map<ll, bool> prims);

// bool isPrime(int n)
// {
//     if (n < 2)
//         return false;
//     if (n == 2 || n == 3)
//         return true;
//     if (n % 2 == 0 || n % 3 == 0)
//         return false;
//     zrc(i, 5, sqrt(n) + 1, 6)
//     {
//         if (n % i == 0 || n % (i + 2) == 0)
//             return false;
//     }
//     return true;
// }

int main() {
    fastio;
    int t = 1;

    if (true) {
        cin >> t;
    }

    // map<ll, bool> prims;
    // for (int i = 5; i < 400000; i += 6)
    // {
    //     if (isPrime(i))
    //     {
    //         prims[i] = true;
    //     }
    //     if (isPrime(i + 2))
    //     {
    //         prims[i + 2] = true;
    //     }
    // }
    z (i, t) {
        int n;
        ll o = 1;
        cin >> n;
        vi a (n);
        z (i, n) {
            cin >> a[i];
        }
        vector<ll> ps (n + 1);
        vector<ll> ss (n + 1);
        zr (i, 1, n + 1) {
            ps[i] = ps[i - 1] + a[i - 1];
            ss[n - i] = ss[n - i + 1] + a[n - i];
        }
        zr (i, 1, n)
        o = max (o, __gcd (ps[i], ss[i]));
        // ll k = ps[n];
        // if (isPrime(ps[n]))
        // {
        //     k = ps[n];
        // }
        // else if (ps[n] % 2 == 0)
        // {
        //     k = 2;
        // }
        // else if (ps[n] % 3 == 0)
        // {
        //     k = 3;
        // }
        // else
        // {
        //     for (int i = 5; (prims[i] || prims[i + 2]) && i <= n - 2; i += 6)
        //     {
        //         int j = (ps[n] % i == 0) ? i : i + 2;
        //         if (ps[n] % j == 0)
        //         {
        //             k = j;
        //             break;
        //         }
        //     }
        // }
        cout << o << "\n";
    }
}