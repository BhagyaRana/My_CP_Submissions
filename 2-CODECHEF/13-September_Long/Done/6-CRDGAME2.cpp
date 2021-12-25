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
// ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

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

// vector<ll> factorial(1e5 + 1);

// void precompute()
// {
//     factorial[0] = 1;

//     for (int i = 1; i <= 100000; i++)
//     {
//         factorial[i] = ((factorial[i - 1] % mod) * (i % mod)) % mod;
//     }
// }

// All Functions Here
ll binpow(ll a, ll b, ll m)
{
    a %= m;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
ll modInverse(ll n, ll mod)
{
    return binpow(n, mod - 2, mod);
}

ll gcd(ll a, ll b, ll &x, ll &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll g = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return g;
}

ll nCr(ll n, ll r)
{
    if (r > n)
    {
        return 0;
    }
    if (r > n - r)
        r = n - r;
    ll a = 1, b = 1;
    for (int i = 0; i < r; i++)
    {
        a = (a * (n - i)) % mod;
        b = (b * (i + 1)) % mod;
    }
    ll x, y;
    gcd(b, mod, x, y);
    ll res = (a * (x % mod + mod) % mod) % mod;
    return res;
}

// All Variables Here

int main()
{
    b_v_r();
    ll n, i;
    // precompute();
    w(t)
    {
        cin >> n;
        ll a[n];
        bool chk = true;
        ll large = -1;
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] > large)
                large = a[i];
        }
        ll cnt = 0;
        for (i = 0; i < n; i++)
        {
            if (a[i] == large)
                cnt++;
        }

        ll m = mod;
        ll two_n = binpow(2, n, m);
        if (cnt % 2 == 0)
        {
            cout << (two_n - (nCr(cnt, cnt / 2) * binpow(2, n - cnt, m)) % mod + mod) % mod << endl;
        }
        else
        {
            cout << two_n << endl;
        }
    }

    return 0;
}