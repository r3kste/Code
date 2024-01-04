#include <bits/stdc++.h>
using namespace std;

#define MOD (ll)(1e9 + 7)
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

struct matrix2 {
    ll mat[2][2];
    matrix2 friend operator* (matrix2 &a, matrix2 &b) {
        matrix2 c;

        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++) {
                c.mat[i][j] = 0;

                for (int k = 0; k < 2; k++) {
                    c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
                }
            }

        return c;
    }
};

struct matrix3 {
    ll mat[3][3];
    matrix3 friend operator* (matrix3 &a, matrix3 &b) {
        matrix3 c;

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) {
                c.mat[i][j] = 0;

                for (int k = 0; k < 3; k++) {
                    c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
                }
            }

        return c;
    }
};

matrix2 matpow (matrix2 a, ll n) { // binexp of matrices
    matrix2 i = {1, 0, 0, 1};

    while (n) {
        if (n & 1) {
            i = i * a;
        }

        a = a * a;
        n >>= 1;
    }

    return i;
}

matrix3 matpow (matrix3 a, ll n) { // binexp of matrices
    matrix3 i = {1, 0, 0, 0, 1, 0, 0, 0, 1};

    while (n) {
        if (n & 1) {
            i = i * a;
        }

        a = a * a;
        n >>= 1;
    }

    return i;
}

double binpow (double a, ll b) {
    double res = 1;

    while (b > 0) {
        if (b & 1) {
            res = res * a;
        }

        a = a * a;
        b >>= 1;
    }

    return res;
}

long pisano (long m) {
    long p = 0;
    long c = 1;
    long n = 0;

    for (int i = 0; i < m * m; i++) {
        long temp = 0;
        temp = c;
        c = (p + c) % m;
        p = temp;

        if (p == 0 && c == 1) {
            return i + 1;
        }
    }

    return m;
}

ll m_fib (ll n, ll m) {
    ll pisanoPeriod = 2000000016;
    n = n % pisanoPeriod;
    ll p = 0;
    ll c = 1;

    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }

    for (int i = 2; i <= n; i++) {
        ll temp = c;
        c = (p + c) % m;
        p = temp % m;
    }

    return c % m;
}

// long pis1ano(long m)
// {
//     long prev = 0;
//     long curr = 1;
//     long res = 0;

//     for (ll i = 0; i < m * m; i++)
//     {
//         long temp = 0;
//         temp = curr;
//         curr = (prev + curr) % m;
//         prev = temp;

//         if (prev == 0 && curr == 1)
//             res = i + 1;
//     }
//     return res;
// }

int solve() {
    fastio;
    ll n;
    cin >> n;
    // n %= 2000000016;
    // // // NAIVE
    LL a = 0, b = 1;

    for (LL i = 2; i <= n; i++) {
        LL temp = (a + b) % MOD;
        a = b % MOD;
        b = temp % MOD;
    }

    cout << b % MOD;
    // Formula??
    // double gold = 1.6180339887498949;
    // double silver = -0.6180339887498949;
    // double o = binpow(gold, n) / sqrt(5);
    // cout << ll(round(o)) % MOD;
    // // Matrix Exponentiation
    // matrix2 mat = {1, 1, 1, 0};
    // cout << matpow(mat, n-1).mat[0][0] % MOD;
    // cout << m_fib(n, MOD);
    // cout << pis1ano(MOD);
    return 0;
}

int main() {
    fastio;
    int t = 1;

    while (t--) {
        solve();
        cout << "\n";
    }
}
