#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

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
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

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

map<pair<int, int>, int> mp;

int pathcnt = 0;

// Graph class represents a directed graph
// using adjacency list representation
class Graph
{
    int V; // No. of vertices
    // Pointer to an array containing
    // adjacency lists
    list<int> *adj;

    // A recursive function used by printAllPaths()
    void printAllPathsUtil(int v1, int v2, bool visited[], int path[], int index);

public:
    Graph(int V);   // Constructor
    bool pathExist; //variable to indicate if path exist or not
    // function to add an edge to graph
    void addEdge(int v, int w);
    void printAllPaths(int v1, int v2);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

// A recursive function to print all paths from 'v1' to 'v2'.
// visited[] keeps track of vertices in current path.
// path[] stores actual vertices and index is current
// index in path[]
void Graph::printAllPathsUtil(int v1, int v2, bool visited[], int path[], int index)
{
    // Mark the current node as visited and store it in path[]
    visited[v1] = true;
    path[index] = v1;
    index++;
    // If current vertex is same as v2, then print
    // current path[]
    if (v1 == v2)
    {
        int i;

        pathExist = true;

        int j = 1;
        for (; j <= index - 1; j++)
        {
            mp[{path[j - 1], path[j]}]++;
        }

        pathcnt++;
    }
    else
    { // If current vertex is not v2
        // Recur for all the vertices adjacent
        // to this vertex
        list<int>::iterator i;
        for (i = adj[v1].begin(); i != adj[v1].end(); ++i)
            if (!visited[*i])
                printAllPathsUtil(*i, v2, visited, path, index);
    }
    // Remove current vertex from path[] and mark it as unvisited
    index--;
    visited[v1] = false;
}

// DFS traversal of the vertices reachable from v.
// It uses recursive prinAllPathsUtil
void Graph::printAllPaths(int v1, int v2)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Create an array to store paths
    int *path = new int[V];

    // Initialize path[] as empty
    int index = 0;

    pathExist = false;

    // Call the recursive helper function to print all paths
    printAllPathsUtil(v1, v2, visited, path, index);
}

int main()
{
    b_v_r();

    int n, m; // nodes & edges (m <= n)
    cin >> n >> m;

    Graph g(n);

    int src, dest;
    cin >> src >> dest;
    src--;
    dest--;

    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        u--;
        v--;
        g.addEdge(u, v);
        g.addEdge(v, u);
    }

    if (src == dest)
    {
        cout << "0" << endl;
        return 0;
    }

    g.printAllPaths(src, dest);

    int ans = 0;

    for (auto ele : mp)
    {
        if (ele.second == pathcnt)
        {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}