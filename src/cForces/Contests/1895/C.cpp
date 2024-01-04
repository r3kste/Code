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

int sum (int n) {
    int sum = 0;

    while (n) {
        sum = sum + n % 10;
        n = n / 10;
    }

    return sum;
}
int solve() {
    fastio;
    int n;
    cin >> n;
    vector<string> a (n);
    map<ll, bool> mp;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll c = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            string t = a[i] + a[j];
            string t1 = a[j] + a[i];
            // int x = stoi(t);
            // int y = stoi(t1);
            // if (mp[x])
            // {
            //     c++;
            //     continue;
            // }
            // if (mp[y])
            // {
            //     c++;
            //     continue;
            // }
            int l = t.size();

            if (l % 2) {
                continue;
            }

            string a1 = t.substr (0, l / 2);
            string b = t.substr (l / 2, l / 2);
            int aa = stoi (a1);
            int bb = stoi (b);
            string a2 = t1.substr (0, l / 2);
            string b1 = t1.substr (l / 2, l / 2);
            int aa1 = stoi (a2);
            int bb1 = stoi (b1);

            if (sum (aa) == sum (bb)) {
                // if (aa == bb)
                // {
                //     c++;
                // }
                // cout << a[i] << " " << a[j] << "\n";
                c++;
                // mp[x] = true;
            }

            if (sum (aa1) == sum (bb1)) {
                // if (aa == bb)
                // {
                //     c++;
                // }
                // cout << a[i] << " " << a[j] << "\n";
                c++;
                // mp[y] = true;
            }

            // cout << t <<" "<<a<<" "<<b<<"\n";
        }
    }

    cout << c + n;
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
