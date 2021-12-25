ll powmod(ll a, ll b, ll p)
{
    a %= p;
    if (a == 0)
        return 0;
    ll product = 1;
    while (b > 0)
    {
        if (b & 1)
        { // you can also use b % 2 == 1
            product *= a;
            product %= p;
            --b;
        }
        a *= a;
        a %= p;
        b /= 2; // you can also use b >> 1
    }
    return product;
}

// A^M-2 is not necessarily the Inverse of A if M is Not Prime
// Use Extended GCD for Non-Prime M
ll inv(ll a, ll p)
{
    return powmod(a, p - 2, p);
}

// <Template For nCr>
// Do-not Change this Upper MAXN, It shoud be 3e5 Only!
const int MAXN = 300500;
const int mod = 1000000007;
using ll = long long;
ll fact[MAXN];
ll invFact[MAXN];

ll fast_pow(ll a, ll p)
{
    ll res = 1;
    while (p)
    {
        if (p % 2 == 0)
        {
            a = (a * a) % mod;
            p /= 2;
        }
        else
        {
            res = (res * a) % mod;
            p--;
        }
    }
    return res;
}

ll nCr(ll n, ll k)
{
    if (k > n)
    {
        return 0;
    }
    return fact[n] * invFact[k] % mod * invFact[n - k] % mod;
}

// IMP! Add this to Precompute Before Test Cases!

// fact[0] = invFact[0] = 1;
// for (int i = 1; i < MAXN; i++)
// {
//     fact[i] = (fact[i - 1] * i) % mod;
//     invFact[i] = fast_pow(fact[i], mod - 2);
// }

// IMP! Add this to Precompute Before Test Cases!

const int md = 998244353;

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

// ---------------------------------TEMPLATE ENDS~---------------------------------
// OPTIMIZATIONS
#pragma GCC optimize("Ofast,03")
#pragma GCC target("sse4,avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

// HEADERS AND NAMESPACE
#include <bits/stdc++.h>
using namespace std;

//CONSTANTS
const int mod = 1000000007;
// const int mod = 998244353;

// COMMONLY USED TYPES
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

//LOOPS
#define FOR(i, l, r) for (int i = l; i <= (r); i++)
#define F0R(i, n) for (int i = 0; i < (n); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i, a) for (int i = (a); i >= 0; i--)
#define trav(x, a) for (auto &x : a)

//SHORT HAND
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int((a).size())
#define fill(x, y) memset(x, y, sizeof(y))
#define all(x) (x).begin(), (x).end() //Forward traversal
#define endl "\n"
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)

ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

#define watch(x) cout << (#x) << " is : " << (x) << "\n"
#define watch2(x, y) cout << (#x) << " is " << (x) << " and " << (#y) << " is " << (y) << "\n"

// First Variable Needs to be Ans like ans = max(ans,xyz)
template <class T>
bool ckmin(T &a, const T &b)
{
    return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T &a, const T &b)
{
    return a < b ? a = b, 1 : 0;
}
//                      BE COOL AND FOCUS ON ACCURATE & SIMPLE CODE!
// ---------------------------------TEMPLATE ENDS~---------------------------------

// All Variables Here

// All Functions Here

void solve()
{
    




    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // If No Test Case, Then Comment it!
    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}
