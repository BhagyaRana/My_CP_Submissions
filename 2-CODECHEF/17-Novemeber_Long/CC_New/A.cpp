// OPTIMIZATIONS
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

// HEADERS AND NAMESPACE
#include <bits/stdc++.h>
using namespace std;

//CONSTANTS
typedef long long ll;
typedef vector<int> vi;
const ll mod = 4294967296;

//LOOPS
// 0 based indexing
#define for0(i, n) for (int i = 0; i < (int)(n); ++i)
// 1 based indexing
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
// closed interver from l to r r inclusive
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
// reverse 0 based.
#define forr0(i, n) for (int i = (int)(n)-1; i >= 0; --i)
// reverse 1 based
#define forr1(i, n) for (int i = (int)(n); i >= 1; --i)

//SHORT HAND
#define pb push_back
#define mp make_pair

// to be used with algorithms that processes a container
// Eg: find(all(c),42)
#define all(x) (x).begin(), (x).end()  //Forward traversal
#define rall(x) (x).rbegin, (x).rend() //reverse traversal

#define endl "\n"

#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)

#define watch(x) cout << (#x) << " is : " << (x) << "\n"
#define watch2(x, y) cout << (#x) << " is " << (x) << " and " << (#y) << " is " << (y) << "\n"

void b_v_r()
{
#ifndef MY_ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

// All Functions Here
const int sz = 300002;

// Adjacency list representation of the tree
vi tree[sz];
bool vis[sz];
vi path[sz];

void bfs(int node)
{
    queue<pair<int, int>> qu;
    qu.push({node, -1});
    vis[node] = true;

    while (!qu.empty())
    {
        pair<int, int> p = qu.front();
        qu.pop();
        vis[p.first] = true;
        for (int child : tree[p.first])
        {
            if (!vis[child])
            {
                qu.push({child, p.first});
                path[child] = path[p.first];
                path[child].push_back(p.first);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    b_v_r();
    // Number of Vertices
    int n;
    // Number of Queries
    int q;
    cin >> n >> q;

    ll wgt[n] = {0};
    for0(i, n)
    {
        cin >> wgt[i];
    }

    int u, v;
    for0(i, n - 1)
    {
        cin >> u >> v;
        u--;
        v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    bfs(0);

    int a, b;
    while (q--)
    {
        cin >> a >> b;
        a--;
        b--;
        ll ans = 0;
        ans = ((ans) % mod + (wgt[a] * wgt[b]) % mod) % mod;
        vi node1 = path[a];
        vi node2 = path[b];
        int sz = node1.size();
        for (int i = 0; i < sz; i++)
        {
            // watch2(node1[i], node2[i]);
            ans = ((ans) % mod + (wgt[node1[i]] * wgt[node2[i]]) % mod) % mod;
        }
        cout << ans << endl;
    }

    return 0;
}
