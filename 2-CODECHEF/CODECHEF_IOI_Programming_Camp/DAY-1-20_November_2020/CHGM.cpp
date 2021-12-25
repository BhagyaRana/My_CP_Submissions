// OPTIMIZATIONS
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

// HEADERS AND NAMESPACE
#include <bits/stdc++.h>
using namespace std;

#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define endl "\n"

typedef long long ll;

// All Functions Here
void solve()
{
    ll n;
    char ch;
    cin >> n >> ch;

    if (n & 1)
    {
        if (ch == 'P')
        {
            cout << "T-Series\n";
        }
        else
        {
            cout << "PewDiePie\n";
        }
    }
    else
    {
        if (ch == 'P')
        {
            cout << "PewDiePie\n";
        }
        else
        {
            cout << "T-Series\n";
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    w(t)
    {
        solve();
    }

    return 0;
}
