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
vector<vector<int>> adj;
vector<bool> visited;
void dfs (int node, int parent) {
    visited[node] = true;

    for (auto surr : adj[node]) {
        if (surr == parent || visited[surr]) {
            continue;
        }

        dfs (surr, node);
    }
}
int solve() {
    fastio;
    int n;
    cin >> n;
    n *= 2;
    string s;
    cin >> s;
    char prev = s[0];
    int c = 1;

    for (int i = 1; i < n; i++) {
        char ch = s[i];

        if (ch == prev && ch == '(') {
            c++;
        }

        prev = s[i];
    }

    cout << c;
    // vi spos;
    // adj = vector<vector<int>> (n);
    // for (int i = 0; i < n; i++)
    // {
    //     char c = s[i];
    //     if (c == '(')
    //     {
    //         spos.pb (i);
    //     }
    // }
    // for (auto i : spos) // goto a '('
    // {
    //     int oc = 1;
    //     int cc = 0;
    //     for (int j = i + 1; j < n; j++) // start from '(' and find balanced bracket sequences
    //     {
    //         char c = s[j];
    //         if (c == '(')
    //         {
    //             oc++;
    //         }
    //         else
    //         {
    //             cc++;
    //         }
    //         if (cc == oc)
    //         {
    //             adj[i].pb (j);
    //             adj[j].pb (i);
    //         }
    //         if (cc > oc)
    //         {
    //             break;
    //         }
    //     }
    // }
    // int c = 0;
    // visited = vector<bool> (n, false);
    // // queue<int> todo;
    // for (int root = 0; root < n; root++)
    // {
    //     if (visited[root])
    //     {
    //         continue;
    //     }
    //     c++;
    //     dfs (root, -1);
    //     // todo.push (root);
    //     // visited[root] = true;
    //     // while (todo.size() > 0)
    //     // {
    //     //     int node = todo.front();
    //     //     todo.pop();
    //     //     for (auto surr : adj[node])
    //     //     {
    //     //         if (visited[surr])
    //     //         {
    //     //             continue;
    //     //         }
    //     //         todo.push (surr);
    //     //         visited[surr] = true;
    //     //     }
    //     // }
    // }
    // cout << c;
    return 0;
}

int main() {
    fastio;
    int t = 1;
    cin >> t;

    while (t--) {
        solve();
        cout << "\n";
    }
}