// OPTIMIZATIONS
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

// HEADERS AND NAMESPACE
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;

// All Functions Here
const int md = 1000000007;

inline void add(int &a, int b)
{
    a += b;
    if (a >= md)
        a -= md;
}

inline void sub(int &a, int b)
{
    a -= b;
    if (a < 0)
        a += md;
}

inline int mul(int a, int b)
{
    return (int)((long long)a * b % md);
}

inline int power(int a, long long b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

inline int inv(int a)
{
    return power(a, md - 2);
}

void solve()
{
    ll n;
    cin >> n;

    if (n <= 5)
    {
        cout << "0" << endl;
        return;
    }

    int n1;

    n1 = (n / 2) - 1;

    int ans = 1;

    ans = mul(ans, n1);
    ans = mul(ans, n1);
    if (n1 & 1)
        sub(ans, 1);

    ans = mul(ans, inv(2));

    cout << ans << endl;

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc = 1;
    cin >> tc;
    // If No Test Case, Then Comment it!
    while (tc--)
    {
        solve();
    }

    return 0;
}
