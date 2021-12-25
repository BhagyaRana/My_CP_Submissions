// OPTIMIZATIONS
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

// HEADERS AND NAMESPACE
#include <bits/stdc++.h>
using namespace std;

//CONSTANTS
const int mod = 1000000007;
const double eps = 1e-9;
const int INF = 0x3f3f3f3f;

#define watch(x) cout << (#x) << " is : " << (x) << "\n"
#define watch2(x, y) cout << (#x) << " is " << (x) << " and " << (#y) << " is " << (y) << "\n"

void b_v_r()
{
#ifndef MY_ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

typedef long long int ll;

#define N 200002

map<pair<int, int>, ll> mp;

// Adjacency list to store edges
vector<int> adj[N];

int used[N];
int max_matching;

ll ans2 = 0;

// Add an edge between U and V in tree
void AddEdge(int u, int v)
{
    // Edge from u to v
    adj[u].push_back(v);

    // Edge from V to U
    adj[v].push_back(u);
}

// Function that finds the maximum
// matching of the DFS
void Matching_dfs(int u, int p)
{
    for (int i = 0;
         i < adj[u].size(); i++)
    {

        // Go further as we are not
        // allowed to go towards
        // its parent
        if (adj[u][i] != p)
        {
            Matching_dfs(adj[u][i], u);
        }
    }

    // If U and its parent P is
    // not taken then we must
    // take &mark them as taken
    if (!used[u] and !used[p] and p != 0)
    {

        // Increment size of edge set
        cout << u << " " << p << endl;

        ans2 = ans2 ^ (mp[{u, p}]);

        max_matching++;
        used[u] = used[p] = 1;
    }
}

// Function to find the maximum
// matching in a graph
void maxMatching()
{
    // Taking 1 as a root of the tree
    Matching_dfs(1, 0);

    // Print maximum Matching
    cout << max_matching << "\n";
}



// Driver Code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // int n = 5;
    int n;
    cin >> n;
    int v, u;
    ll w;
    ll ans = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> v >> u >> w;
        // AddEdge(v, u);
        mp.insert({v, u}, w);
        ans ^= w;
    }

    // Function Call
    // maxMatching();

    cout << ans2 << endl;
    cout << ans << endl;
    cout << ans^ans2 << endl;

    return 0;
}
