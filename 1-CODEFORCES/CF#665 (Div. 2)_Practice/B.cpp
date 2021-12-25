#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define endl "\n"
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
typedef long long ll;
#define mk(arr, n, type) type *arr = new type[n]
const int mod = 1000000007;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

#define watch(x) cout << (#x) << " is : " << (x) << "\n"
#define watch2(x, y) cout << (#x) << " is " << (x) << " and " << (#y) << " is " << (y) << "\n"

void b_v_r()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

// All Functions Here

// All Variables Here

int main()
{
    b_v_r();
    ll x1, y1, z1, x2, y2, z2;
    ll min1, min2, min3;
    w(t)
    {
        ll ans = 0;
        cin >> x1 >> y1 >> z1;
        cin >> x2 >> y2 >> z2;
        min1 = min(z1, y2);
        // {2,1} pAirs Counted
        ans += (min1 * 2);
        z1 -= min1;
        y2 -= min1;

        // {0,2} & (2,2)
        min2 = min(x1, z2);
        x1 -= min2;
        z2 -= min2;

        min3 = min(z1, z2);
        z1 -= min3;
        z2 -= min3;

        if (z2)
            ans -= (2 * z2);

        cout << ans << endl;
    }

    return 0;
}