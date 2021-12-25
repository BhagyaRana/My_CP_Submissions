#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

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
ll power(ll a, ll b, ll mod1)
{
    if (a == 1)
        return 1;
    if (b == 0)
        return 1;
    ll c = power(a, b / 2, mod1);
    ll res = 1;
    if (b % 2)
    {
        res = c * c;
        if (res >= mod1)
            res %= mod1;
        res *= a;
    }
    else
        res = c * c;
    if (res >= mod1)
        res %= mod1;
    return res;
}
ll modInv(ll a) { return power(a, mod - 2); }

ll fact[1], inv[1];
void factorial(ll n)
{
    fact[0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        fact[i] = fact[i - 1] * i;
        if (fact[i] >= mod)
            fact[i] %= mod;
    }
}
void InvFactorial(ll n)
{
    inv[0] = 1;
    for (ll i = 1; i <= n; i++)
        inv[i] = modInv(fact[i]);
}

ll ncr(ll n, ll r)
{
    if (n < r || n < 0 || r < 0)
        return 0;
    ll b = inv[n - r];
    ll c = inv[r];
    ll a = fact[n] * b;
    if (a >= mod)
        a %= mod;
    a *= c;
    if (a >= mod)
        a %= mod;
    return a;
}

// All Variables Here

void solve()
{
    
}

int main()
{
    b_v_r();

    int t;
    scanf("%d", &t);
    while (t--)
        solve();

        

    return 0;
}