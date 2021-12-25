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

const int maxn = 300010;

vector<ll> adj[maxn], subval, val;
vector<pl> mypair;

struct greater1
{
    template <class T>
    bool operator()(T const &a, T const &b) const { return a > b; }
};

const int md = mod;

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

// All Functions Here
void dfs(int child, int par = -1)
{
    for (auto x : adj[child])
    {
        if (x == par)
            continue;
        // Call Recursively for its Sub-Child
        dfs(x, child);
    }

    // Clear the Old Order of Nodes
    mypair.clear();

    // Insert the sub-val & node in mypair
    for (auto x : adj[child])
    {
        if (x != par)
            mypair.pb({subval[x], x});
    }

    // All Nodes will be Sorted according to their Sub-Values
    sort(all(mypair), greater1());

    // Intialize starting from 1,2,...
    ll cnt = 1;
    for (auto p : mypair)
    {
        val[p.second] = cnt;
        cnt++;
    }

    for (auto x : adj[child])
    {
        // If Current Element is not the Parent, Add it to Sub-Value
        if (x != par)
            subval[child] += (val[x] * subval[x]);
    }

    return;
}

void solve()
{
    ll N, X, u, v;
    cin >> N >> X;

    subval.assign(N, 1);
    val.assign(N, 0);

    F0R(i, N)
    vector<ll>().swap(adj[i]);

    F0R(i, N - 1)
    {
        cin >> u >> v;
        adj[u - 1].pb(v - 1);
        adj[v - 1].pb(u - 1);
    }

    // Call the DFS Function
    dfs(0);

    int t1 = (subval[0]) % mod;

    // Multiply X with all the Nodes for GCD Condition
    cout << mul(t1, X) << "\n";

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
