#include <bits/stdc++.h>
using namespace std;

#define to(i, a, b, c) for (int(i) = (a); (i) < b; (i) += c)
#define fro(i, a, b, c) for (int(i) = (b)-1; (i) >= (a); (i) -= c)

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

typedef long long int ll;
typedef pair<int, int> ii;

typedef vector<int> vi;
typedef vector<long long int> vll;

int solve();

int main() {
    fastio;
    int t = 1;

    if (false) {
        cin >> t;
    }

    while (t--) {
        solve();
        cout << "\n";
    }
}

int solve() {
    fastio;
    int n, m;
    cin >> n >> m;
    ll s = 0;
    vll a (n);
    // vll ps(n + 1);
    // ps[0] = 0;
    to (i, 0, n, 1) {
        cin >> a[i];
        // ps[i + 1] = ps[i] + a[i];
    }
    ll tblock = 0;
    // vi b(m);
    to (i, 0, m, 1) {
        ll temp;
        cin >> temp;

        // int s=1,e=n;
        // int m=(s+e)/2;
        // ll block=0,door=0;
        // while(s<=e) {
        //     if(temp==ps[m]) {
        //         block = m;
        //         door = m - ps[m-1];
        //     }
        //     if(temp<a[m]) {
        //         if(temp > a[s]) {

        //         }
        //     }
        // }

        // to(i, tblock, n + 1, 1)
        // {
        //     if (temp <= ps[i])
        //     {
        //         tblock = i;
        //         cout << i << " " << temp - ps[i - 1] << "\n";
        //         break;
        //     }
        // }

        while (s + a[tblock] < temp) {
            s += a[tblock++];
        }

        cout << tblock + 1 << " " << temp - s << "\n";
    }
    return 0;
}