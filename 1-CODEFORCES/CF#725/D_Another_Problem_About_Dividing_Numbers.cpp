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

// This will Generate the Prime Seive till 10^7
bool prime[15000105];
void sieve(int n)
{
    for (ll i = 0; i <= n; i++)
        prime[i] = 1;
    for (ll p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    prime[1] = prime[0] = 0;
}

vector<ll> primelist;
bool __primes_generated__ = 0;

// This will Generate Prime till 'n'
void genprimes(int n)
{
    __primes_generated__ = 1;
    sieve(n + 1);
    for (ll i = 2; i <= n; i++)
        if (prime[i])
            primelist.push_back(i);
}

// This will Factorize 'n'
vector<ll> factors(ll n)
{
    if (!__primes_generated__)
    {
        cerr << "Call genprimes you dope" << endl;
        exit(1);
    }

    vector<ll> facs;

    for (ll i = 0; primelist[i] * primelist[i] <= n && i < primelist.size(); i++)
    {
        if (n % primelist[i] == 0)
        {
            while (n % primelist[i] == 0)
            {
                n /= primelist[i];
                facs.push_back(primelist[i]);
            }
        }
    }
    if (n > 1)
    {
        facs.push_back(n);
    }
    sort(facs.begin(), facs.end());
    return facs;
}

void solve()
{
    ll x, y, k;
    cin >> x >> y >> k;
    // EDGE CASE
    if (k == 1)
    {
        if ((x % y == 0 || y % x == 0) && (x != y))
            cout << "YES\n";
        else
            cout << "NO\n";
        return;
    }

    vll a = factors(x);
    vll b = factors(y);

    if (k <= a.size() + b.size())
        cout << "YES\n";
    else
        cout << "NO\n";

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // If No Test Case, Then Comment it!
    genprimes(1e6);
    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}
