#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, i;
    cin >> t;

    while (t--)
    {
        cin >> n;
        vector<pair<int, int>> a (n);

        for (i = 0; i < n; a[i].second = i, i++)
        {
            cin >> a[i].first;
        }

        sort (begin (a), end (a));

        for (auto i : a)
        {
            cout << i.second << "\n";
        }
    }
}
