#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

typedef long long int ll;
typedef pair<int, int> ii;

typedef vector<int> vi;
typedef vector<long long int> vll;

int bsearch (vi a, int s, int e, int n) {
    int m = (s + e) / 2;

    if (s > e) {
        return -1;
    } else if (n == a[m]) {
        return m;
    } else if (n < a[m]) {
        return bsearch (a, s, m - 1, n);
    } else {
        return bsearch (a, m + 1, e, n);
    }
}

int search (vi a, int n) {
    sort (begin (a), end (a));
    return bsearch (a, 0, a.size() - 1, n);
}

int main() {
}