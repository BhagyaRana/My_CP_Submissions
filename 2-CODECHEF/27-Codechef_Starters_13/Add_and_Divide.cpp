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
#define FOR(i, l, r) for (ll i = l; i <= (r); i++)
#define F0R(i, n) for (ll i = 0; i < (n); i++)
#define FORd(i, a, b) for (ll i = (b)-1; i >= a; i--)
#define F0Rd(i, a) for (ll i = (a); i >= 0; i--)
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

void prime(int n, vector<int> &v)
{
    // Print the number of 2s that divide n
    while (n % 2 == 0)
    {
        v.pb(2);
        n = n / 2;
    }

    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            v.pb(i);
            n = n / i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        v.pb(n);
    // cout << n << " ";
}

void solve()
{
    int a, b;
    cin >> a >> b;
    // Check if b is Divisible by All Prime Factors of a
    vi v;
    prime(a, v);

    bool ok = true;

    for (auto x : v)
    {
        if (b % x != 0)
        {
            ok = false;
            break;
        }
    }

    if (ok)
        cout << "YES\n";
    else
        cout << "NO\n";

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // sieve();
    // If No Test Case, Then Comment it!
    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}
