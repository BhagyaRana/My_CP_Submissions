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
typedef long long int ll;
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

ll isqrt(ll x)
{
    ll y = sqrt(x);
    if (y * y == x)
        return y;
    return -1;
}

#define getunique(v)                      \
    {                                     \
        sort(all(v));                     \
        v.erase(unique(all(v)), v.end()); \
    }

// This will return Divisors of 'n'
vector<ll> getdivs(ll n)
{
    vector<ll> divs;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            divs.push_back(i);
            divs.push_back(n / i);
        }
    }

    getunique(divs);
    return divs;
}

set<ll> is_square;

void prework()
{
    FOR(i, 1, 1e6)
    {
        is_square.insert(i * i);
    }
}

void solve()
{
    ll x;
    cin >> x;

    if (x <= 2)
    {
        cout << "0\n";
        return;
    }

    set<pair<ll, ll>> myset;

    // CASE 1: x == m^2 + n^2
    for (int i = 1; i * i <= x; ++i)
    {
        if (is_square.count(x - (i * i)))
        {
            ll x1 = i;
            ll x2 = sqrt(x - (i * i));
            // if ((x2 * x2 - x1 * x1 > 0) && (x1 != 0 && x2 != 0))
            // {
                // cout << "CASE1\n";
                // watch2(x1, x2);
                myset.insert({min(x1, x2), max(x1, x2)});
            // }
        }
    }

    // CASE 2: x == m^2 - n^2
    vll d = getdivs(x);
    F0R(i, sz(d))
    {
        ll d1 = d[i];
        ll d2 = x / d1;
        ll sm = min(d1, d2);
        ll bg = max(d1, d2);
        if ((bg - sm) % 2 == 0 && (bg + sm) % 2 == 0)
        {
            ll x1 = (bg - sm) / 2;
            ll x2 = (bg + sm) / 2;
            // if ((x2 * x2 - x1 * x1 > 0) && (x1 != 0 && x2 != 0))
            // {
                // cout << "CASE2\n";
                // watch2(x1, x2);
                myset.insert({min(x1, x2), max(x1, x2)});
            // }
        }
    }

    if (x % 2 == 0)
    {
        // CASE 3: x == 2*m*n
        x = x/2;
        vll d = getdivs(x);
        F0R(i, sz(d))
        {
            ll d1 = d[i];
            ll d2 = x / (d1);
            ll sm = min(d1, d2);
            ll bg = max(d1, d2);
            ll x1 = sm;
            ll x2 = bg;
            // if ((x2 * x2 - x1 * x1 > 0) && (x1 != 0 && x2 != 0))
                myset.insert({min(x1, x2), max(x1, x2)});
        }
    }

    // watch(x);

    // for (auto p : myset)
    // {
    //     cout << p.first << " " << p.second << endl;
    // }

    cout << myset.size() << endl;

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    prework();

    // If No Test Case, Then Comment it!
    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}
