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
#define fill(x, y) str_pathset(x, y, sizeof(y))
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

ll ans;
vector<vi> adj;
// Straight Paths
vector<int> str_path;
vector<int> csum;

// All Functions Here
const int md = mod;

inline void add(int &a, int b)
{
    a += b;
    a %= mod;
    // if (a >= md)
    //     a -= md;
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

void dfs(int cur, int par);

void solve()
{
    ans = 0;
    // N Nodes
    int n;
    cin >> n;

    // Allocate Required Memory for Input
    adj.resize(n + 1);
    str_path.resize(n + 1);
    csum.resize(n + 1);

    // Input Taken
    F0R(i, n - 1)
    {
        int l, r;
        cin >> l >> r;
        adj[l].pb(r);
        adj[r].pb(l);
    }

    // Call the DFS Function
    dfs(1, 1);

    // Cumulative Sum at index 1 will have final answer
    cout << (csum[1]) % mod << endl;

    // To re-use the same Vector
    adj.clear();
    str_path.clear();
    csum.clear();

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

void dfs(int cur, int par)
{
    // Intialize the Current Node
    str_path[cur] = 1;
    csum[cur] = 1;
    ll sum = 0, cnt = 0;

    F0R(i, sz(adj[cur]))
    {
        // Get the Current Node
        ll node = adj[cur][i];
        // If Node != Parent
        if (node != par)
        {
            // Recursively Called its Child
            dfs(node, cur);

            // Cumulately Add the node to its Parent [2 -> Either Take it or Not]
            add(str_path[cur], (2 * str_path[node])%mod);

            // Add the sum of node to Parent
            add(csum[cur], csum[node]);
            // Also add in Cumulative Sume the Value in str_path
            add(csum[cur], str_path[node]);

            sum += str_path[node];
            cnt++;
        }
    }

    F0R(i, sz(adj[cur]))
    {
        // Get the Current Node
        ll node = adj[cur][i];
        // If Node != Parent
        if (node != par)
        {
            // Add the Total Ways to Chose from straight path [str_path[node]*(sum-str_path[node])]
            ll t = (str_path[node] * ((sum - str_path[node] + mod) % mod)) % mod;
            add(csum[cur], t);
        }
    }
    return;
}