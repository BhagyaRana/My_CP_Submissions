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
    ll n, m;
    cin >> n >> m;

    ll ans = 0;

    // All Pairs with {1,2},{1,3},{1,4},...{1,n} Included
    ans += (n - 1);

    vll freq(n + 1, 0);

    // OPTIMIZED 0(N*log(N)) APPROACH

    FOR(a, 2, n)
    {
        // (m%a)b = m%a [Since it is Given b>a]
        ll r = m % a;

        // Add the Frequency of Remainder 'r'
        ans += freq[r];

        // Increment all its Multiples r,r + a, r + 2*a,...
        // Since (r+a)%a == (r+2a)%a == ...
        for (ll j = r; j <= n; j += a)
        {
            freq[j]++;
        }
    }

    cout << ans << endl;

    // BRUTE FORCE APPROACH

    // for (int i = 1; i < n; i++)
    // {
    //     for (int j = i + 1; j <= n; j++)
    //     {
    //         t1 = ((m) % i) % j;
    //         t2 = ((m) % j) % i;
    //         if (t1 == t2)
    //         {
    //             // watch2(i, j);
    //             ans++;
    //         }
    //     }
    // }

    // cout << ans << endl;

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
