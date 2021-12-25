// OPTIMIZATIONS
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

// HEADERS AND NAMESPACE
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

// COMMONLY USED TYPES
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef unsigned int uint;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;
typedef map<int, int> mii;

#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
// Avoiding wrap around of size()-1 where size is a unsigned int.
#define sz(a) int((a).size())

#define watch(x) cout << (#x) << " is : " << (x) << "\n"
#define watch2(x, y) cout << (#x) << " is " << (x) << " and " << (#y) << " is " << (y) << "\n"

void b_v_r()
{
#ifndef MY_ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

// Keep All Variables Here [Global]
const int N = 300005;
int n, q, max_depth = 0;
// For Storing Tree & memo for One Level Results
vi g[N], memo[N];
// For Storing Answers at particular level
vector<vi> level;
int parent[N], depth[N], idx[N];
// VERY IMP : Unsigned Int -> Mod 2^32 Directly Karta Hai
uint wt[N], dot[N];
bool known[N];

// All Functions Here
void dfs(int v, int par = 1, int dep = 0)
{
    parent[v] = par;
    depth[v] = dep;
    max_depth = max(max_depth, dep);
    dot[v] = dot[par] + (wt[v] * wt[v]);
    for (auto child : g[v])
    {
        if (child == par)
            continue;
        dfs(child, v, dep + 1);
    }
}

uint query(int a, int b)
{
    uint total = 0;
    while (a != b and !known[a])
    {
        total += wt[a] * wt[b];
        a = parent[a];
        b = parent[b];
    }
    // Condition #1 : a == b
    if (a == b)
    {
        total += dot[a];
    }
    // Condition #2 : known[a] == true
    else
    {
        int lvlsz = level[depth[a]].size();
        total += memo[depth[a]][idx[a] * lvlsz + idx[b]];
    }
    return total;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // b_v_r();
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        cin >> wt[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);

    level = vector<vi>(max_depth + 1);
    // Store all Numbers at Same Level
    for (int i = 1; i <= n; i++)
    {
        level[depth[i]].push_back(i);
    }

    // SQUARE ROOT DECOMPOSITION
    // BLOCK SIZE
    int k = sqrt(n);
    for (int i = 0; i <= max_depth; i += k)
    {
        // Find the Level with minimum Nodes
        int lv = i, sz = level[i].size();
        for (int j = i; j <= min(i + k, max_depth); j++)
        {
            if (level[j].size() < sz)
            {
                sz = level[j].size();
                lv = j;
            }
        }

        // Give ID to each element at same level
        int id = 0;
        for (auto x : level[lv])
        {
            idx[x] = id++;
        }

        for (auto x : level[lv])
        {
            for (auto y : level[lv])
            {
                // Store the Answer
                if (idx[x] <= idx[y])
                {
                    memo[lv].push_back(query(x, y));
                }
                else
                {
                    memo[lv].push_back(memo[lv][idx[y] * sz + idx[x]]);
                }
            }
            known[x] = true;
        }
    }

    // ALL PRECOMPUTATION OVER

    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cout << query(u, v) << endl;
    }

    return 0;
}
