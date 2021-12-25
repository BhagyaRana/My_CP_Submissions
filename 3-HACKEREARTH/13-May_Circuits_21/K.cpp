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
typedef unsigned long long int ll;
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

void solve()
{
    ll x;
    cin >> x;

    if (x <= 2)
    {
        cout << "0\n";
        return;
    }

    set<pair<ll, pair<ll, ll>>> myset;

    // ll lft = 1;
    // ll rgt = x; // sqrt(X)
    // ll X = x * x;
    // while (lft <= rgt)
    // {
    //     ll Y = (lft * lft) + (rgt * rgt);
    //     if (Y > X)
    //     {
    //         rgt--;
    //     }
    //     else if (X > Y)
    //     {
    //         lft++;
    //     }
    //     else
    //     {
    //         // Y == X
    //         vector<ll> tmp;
    //         tmp.pb(lft);
    //         tmp.pb(rgt);
    //         tmp.pb(x);
    //         sort(all(tmp));

    //         // watch(x);
    //         // cout << "HERE" << endl;
    //         // cout << tmp[0] << " " << tmp[1] << " " << tmp[2] << endl;

    //         myset.insert({tmp[0], {tmp[1], tmp[2]}});

    //         lft++;
    //     }
    // }

    ll lmt = ceil((double)x / (double)sqrt(2)) + 1;

    for (ll i = 1; i <= lmt; i++)
    {
        ll side = (x * x) - (i * i);
        if (side == 0)
            continue;
        ll t = isqrt(side);
        if (t != -1)
        {
            vector<ll> tmp;
            tmp.pb(i);
            tmp.pb(x);
            tmp.pb(t);
            sort(all(tmp));

            // watch(x);
            // cout << "HERE" << endl;
            // cout << tmp[0] << " " << tmp[1] << " " << tmp[2] << endl;

            myset.insert({tmp[0], {tmp[1], tmp[2]}});
        }
    }

    // for (ll i = 1; i <= 5000000; i++)
    // {
    //     ll hypo = (i * i) + (x * x);
    //     ll t = isqrt(hypo);
    //     if (t != -1)
    //     {
    //         vector<ll> tmp;
    //         tmp.pb(i);
    //         tmp.pb(x);
    //         tmp.pb(t);
    //         sort(all(tmp));
    //         myset.insert({tmp[0], {tmp[1], tmp[2]}});
    //     }
    // }

    vll d = getdivs(x * x);
    for (ll i = 0; i < d.size(); i++)
    {
        ll d1 = d[i];
        ll d2 = (x * x) / d1;
        ll sm = min(d1, d2);
        ll bg = max(d1, d2);
        if (((bg - sm) % 2 == 0 && (bg + sm) % 2 == 0) && ((bg - sm) != 0))
        {
            ll n1 = (bg + sm) / 2;
            ll n2 = (bg - sm) / 2;
            vector<ll> tmp;
            tmp.pb(n1);
            tmp.pb(n2);
            tmp.pb(x);
            sort(all(tmp));
            myset.insert({tmp[0], {tmp[1], tmp[2]}});
        }
    }

    // watch(x);

    // for (auto p : myset)
    // {
    //     cout << p.first << " " << p.second.first << " " << p.second.second << endl;
    // }

    cout << myset.size() << endl;

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
