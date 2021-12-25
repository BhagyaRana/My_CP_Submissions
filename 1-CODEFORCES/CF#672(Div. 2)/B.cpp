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
int mymsb(ll x)
{
    return (int)log2(x) + 1;
}

// All Variables Here

int main()
{
    b_v_r();
    ll n, i;
    w(t)
    {
        cin >> n;
        ll a[n + 1] = {0};
        int msb[n + 1] = {0};
        for (i = 1; i <= n; i++)
        {
            cin >> a[i];
            msb[i] = mymsb(a[i]);
        }
        // If MSB is Different
        // AND -> 0 & XOR->1 : XOR>AND
        // If MSB is Same
        // AND -> 1 & XOR->0 : XOR<=AND
        // 10^9 Requires only 30 Bits
        int bits[33] = {0};
        for (i = 1; i <= n; i++)
        {
            bits[msb[i]]++;
        }
        ll ans = 0;
        for (i = 1; i <= 32; i++)
        {
            if (bits[i] > 1)
                ans += (bits[i] * (bits[i] - 1)) / 2;
        }
        cout << ans << endl;
    }

    return 0;
}