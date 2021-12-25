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

// Since k<=1e6 So We Require 4 Times the Array
const int MAXN = 4000002;

int mem[MAXN], ans[MAXN];

void precompute();

void solve()
{
    int k;
    cin >> k;
    cout << ans[4 * k + 1] << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    precompute();
    // If No Test Case, Then Comment it!
    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}

void init1()
{
    // Initilize the mem & ans
    F0R(i, MAXN)
    {
        mem[i] = i;
        ans[i] = 0;
    }
}

void precompute()
{
    init1();

    for (int i = 2; i < MAXN; i++)
    {
        if (mem[i] == i)
        {
            mem[i] = i - 1;
            // Idea is Similar to Seive of Eratosthenes
            for (int j = 2 * i; j < MAXN; j += i)
            {
                // For all the Multiples of i
                // It Works Like GP common Factor (i)/(i-1) [>1]
                mem[j] = (mem[j] / i) * (i - 1);
            }
        }
    }

    // Idea is Similar to Seive of Eratosthenes
    for (int i = 1; i < MAXN; i++)
    {
        // {1,2}, {1,3}, .... {1,n} = n-1 Pairs Added
        ans[i] += (i - 1);
        for (int j = 2 * i; j < MAXN; j += i)
        {
            ans[j] += i * (ceil(((mem[j / i]) * 1.0) / (2 * 1.0)));
        }
    }
}
