#include <iostream>
using namespace std;
int main()
{
    int t, n, p, c;
    string s;
    cin >> t;

    while (t--)
    {
        cin >> n >> s;

        for (p = c = 0; p < n / 2;)
        {
            c += (s[p] != s[n - ++p]);
        }

        cout << ((n % 2 || !c % 2) ? "YES\n" : "NO\n");
    }
}