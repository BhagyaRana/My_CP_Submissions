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
#define fi first
#define se second

// to be used with algorithms that processes a container
// Eg: find(all(c),42)
#define all(x) (x).begin(), (x).end()  //Forward traversal
#define rall(x) (x).rbegin, (x).rend() //reverse traversal

//FIND
// find if a given value is present in a container. Container version.
// Runs in log(n) for set and map
#define present(c, x) ((c).find(x) != (c).end())
//find version works for all containers. This is present in std namespace.
#define cpresent(c, x) (find(all(c), x) != (c).end())

#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define endl "\n"

// COMMONLY USED TYPES
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;
typedef map<int, int> mii;

#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}
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
// All Variables Here
int n, m;
vector<vi> adj;

// All Functions Here
vi bfs(int src)
{
    vi par(n + 1, 0);
    // -1 to Indicate -> Node is Not Visitable from SRC
    vi dist(n + 1, -1);
    queue<int> q;

    q.push(src);
    dist[src] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int nb : adj[u])
        {
            if (dist[nb] != -1)
                continue;

            dist[nb] = dist[u] + 1;
            par[nb] = u;
            q.push(nb);
        }
    }

    return dist;
}

// DFS to Detect Cycles
bool cycle_found = 0;
void dfs(int i,int par,vi &vis,bool &cycle_found)
{
    vis[i] = 1;
    for(int nb:adj[i])
    {
        if(nb==par)
        {
            continue;
        }
        if(!vis[nb])
        {
            dfs(nb,i,vis,cycle_found);
        }
        else
        {
            cycle_found = true;
        }
    }
}

bool find_cycle()
{
    bool cycle_found = 0;
    vi  vis(n+1,0);

    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(i,-1,vis,cycle_found);
        }
    }

    return cycle_found;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // b_v_r();
    cin >> n >> m;
    adj.resize(n + 1);

    while (m--)
    {
        int i, j;
        cin >> i >> j;
        adj[i].pb(j);
        adj[j].pb(i);
    }

    vi dist = bfs(1);

    for1(i, n)
    {
        cout << i << " " << dist[i] << endl;
    }

    return 0;
}