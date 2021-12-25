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
ll power(ll a, ll b)
{
    ll result = 1;
    while (b)
    {
        if (b % 2)
            result *= a;
        a *= a;
        b /= 2;
    }
    return result;
}
ll inverse(ll a, ll p)
{
    return power(a, p - 2);
}

// All Variables Here

int main()
{
    b_v_r();

    ll n, i, j, k;

    cin >> n;

    ll a[n];

    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    ll l, r, size, zrocnt;

    ll q;
    cin >> q;
    while (q--)
    {
        cin >> l >> r;
        ll ans = a[l];
        for (i = l; i <= r; i++)
        {
            ans = ans & a[i];
        }
        // watch(ans);
        if (ans > 0)
        {
            cout << 0 << endl;
        }
        else
        {
            int zr[32] = {0};
            size = r - l + 1;
            for (i = l; i <= r; i++)
            {
                ans = ans & a[i];
                bitset<32> b(a[i]);
                for (k = 0; k < 32; k++)
                {
                    if (!b[k])
                    {
                        zr[k]++;
                    }
                }
            }
            ll min1 = 1e18, tmp;
            for (i = 0; i < 32; i++)
            {
                tmp = zr[i] * power(2, i);
                if (tmp < min1)
                    min1 = tmp;
            }

            cout << min1 << endl;
        }
    }

    return 0;
}