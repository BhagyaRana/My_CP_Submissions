#pragma GCC optimize("O2")

#include <bits/stdc++.h>
using namespace std;

#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define endl "\n"
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
typedef long long ll;
#define mk(arr, n, type) type *arr = new type[n]
const int mod = 1000000007;
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

#define watch(x) cout << (#x) << " is : " << (x) << "\n"
#define watch2(x, y) cout << (#x) << " is " << (x) << " and " << (#y) << " is " << (y) << "\n"

void b_v_r()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

vector<vector<int>> adj; // graph represented as an adjacency list
int n; // number of vertices

vector<bool> visited;

void dfs(int v)
{
    visited[v] = true;
    for (int u : adj[v])
    {
        if (!visited[u])
            dfs(u);
    }
}

int main()
{
    b_v_r();
    int u, v, i;

    w(t)
    {

        cin >> n;

        int p[n+1] ={ 0 }; // ith day which city start
        ll a[n+1] ={ 0 }; // population of city
        ll b[n+1] ={ 0 }; // intial fruits in city
        int ans[n+1] ={ -1 }; // answer array  

        for (i=1;i<=(n-1);i++)
        {
            cin >> u >> v;
            // Vertex u and v connected by edge

        }

        for (i=1;i<=n;i++) cin >> p[i];
        for (i=1;i<=n;i++) cin >> a[i];
        for (i=1;i<=n;i++) cin >> b[i];







    }

    return 0;
}

