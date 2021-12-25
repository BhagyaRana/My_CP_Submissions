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

// Function to form edge between

// two vertices src and dest
void add_edge(vector<ll> adj[], ll src, ll dest)
{
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}

// Function which finds all the paths and stores it in paths array
void find_paths(vector<vector<ll>> &paths, vector<ll> &path, vector<ll> parent[], ll n, ll u)
{
    // Base Case
    if (u == -1)
    {
        paths.push_back(path);
        return;
    }

    // Loop for all the parents of the given vertex
    for (ll par : parent[u])
    {

        // Insert the current vertex in path
        path.push_back(u);

        // Recursive call for its parent
        find_paths(paths, path, parent, n, par);

        // Remove the current vertex
        path.pop_back();
    }
}

// Function which performs bfs from the given souce vertex
void bfs(vector<ll> adj[], vector<ll> parent[], ll n, ll start)
{
    // dist will contain shortest distance
    // from start to every other vertex
    vector<ll> dist(n, 1e9);

    queue<ll> q;

    // Insert source vertex in queue and make
    // its parent -1 and distance 0
    q.push(start);
    parent[start] = {-1};
    dist[start] = 0;

    // Untill Queue is empty
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        for (ll v : adj[u])
        {
            if (dist[v] > dist[u] + 1)
            {

                // A shorter distance is found
                // So erase all the previous parents
                // and insert new parent u in parent[v]
                dist[v] = dist[u] + 1;
                q.push(v);
                parent[v].clear();
                parent[v].push_back(u);
            }
            else if (dist[v] == dist[u] + 1)
            {

                // Another candidate parent for
                // shortes path found
                parent[v].push_back(u);
            }
        }
    }
}

// Function which prints all the paths
// from start to end
ll print_paths(vector<ll> adj[], ll n, ll start, ll end)
{
    vector<vector<ll>> paths;
    vector<ll> path;
    vector<ll> parent[n];

    // Function call to bfs
    bfs(adj, parent, n, start);

    // Function call to find_paths
    find_paths(paths, path, parent, n, end);

    return (paths.size()) % mod;

    // for (auto v : paths)
    // {

    //     // Since paths contain each
    //     // path in reverse order,
    //     // so reverse it
    //     reverse(v.begin(), v.end());

    //     // Print node for the current path
    //     for (int u : v)
    //         cout << u << " ";
    //     cout << endl;
    // }
}

void solve()
{
    ll n, m, u, v;
    cin >> n >> m;

    vector<ll> adj[n];

    for (ll i = 0; i < m; i++)
    {
        cin >> u >> v;
        u--, v--;
        add_edge(adj, u, v);
    }

    ll src = 0;
    ll dest = n - 1;

    cout << print_paths(adj, n, src, dest);

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // If No Test Case, Then Comment it!
    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}
