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

ll min_sleep = 1e15;

// cost to move from u -> v
ll cost[1001][1001] = {0};

ll C[1001] = {0}, H[1001] = {0};

// All Functions Here
// A directed graph using adjacency list representation
class Graph
{
    int V;          // No. of vertices in graph
    list<int> *adj; // Pointer to an array containing adjacency lists

    // A recursive function used by printAllPaths()
    void printAllPathsUtil(int, int, bool[], int[], int);

public:
    Graph(int V); // Constructor
    void addEdge(int u, int v);
    void printAllPaths(int s, int d);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v); // Add v to u’s list.
}

// Prints all paths from 's' to 'd'
void Graph::printAllPaths(int s, int d)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];

    // Create an array to store paths
    int *path = new int[V];
    int path_index = 0; // Initialize path[] as empty

    // Initialize all vertices as not visited
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function to print all paths
    printAllPathsUtil(s, d, visited, path, path_index);
}

// A recursive function to print all paths from 'u' to 'd'.
// visited[] keeps track of vertices in current path.
// path[] stores actual vertices and path_index is current
// index in path[]
void Graph::printAllPathsUtil(int u, int d, bool visited[], int path[], int path_index)
{
    // Mark the current node and store it in path[]
    visited[u] = true;
    path[path_index] = u;
    //    path_index++;

    // If current vertex is same as destination, then print
    // current path[]
    if (u == d)
    {
        int i;
        ll stamina = 0LL;
        ll curr_sleep = 0LL;
        bool flag = true;
        while (i < path_index)
        {
            if (stamina >= cost[path[i]][path[i + 1]])
            {
                stamina -= cost[path[i]][path[i + 1]];
                i++;
            }
            else
            {
                // Need to Sleep
                curr_sleep += H[path[i]];
                stamina = C[path[i]];

                if (stamina < cost[path[i]][path[i + 1]])
                {
                    flag = false;
                    // Path is Invalid
                    break;
                }
            }
        }

        if (flag)
        {
            if (curr_sleep < min_sleep)
            {
                min_sleep = curr_sleep;
            }
        }

        // for (int i = 0; i <= path_index; i++)
        //     cout << path[i] << " ";
        // cout << endl;
    }
    else // If current vertex is not destination
    {
        // Recur for all the vertices adjacent to current vertex
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (!visited[*i])
                printAllPathsUtil(*i, d, visited, path, path_index + 1);
    }

    // Remove current vertex from path[] and mark it as unvisited
    //    path_index--;
    visited[u] = false;
}
// All Variables Here

int main()
{
    b_v_r();
    int i, j, k;

    int n; //Number of skill levels | Nodes
    int m; //Number of fesible transitions | Edges
    int a; // Initial skill level
    int b; // Ultimate skill level

    cin >> n >> m;

    Graph g(n);

    int src, dest;
    cin >> src >> dest;
    src--;
    dest--;

    int u, v;
    ll z;
    for (int i = 0; i < m; i++)
    {
        // x -> y at cost of stamina z
        // y -> x at cost of stamina z
        cin >> u >> v >> z;
        u--;
        v--;
        g.addEdge(u, v);
        cost[u][v] = z;
        g.addEdge(v, u);
        cost[v][u] = z;
    }

    for (i = 0; i < n; i++)
    {
        // stamina = ci at cost of hi amount of sleep
        cin >> C[i] >> H[i];
    }

    if (src == dest)
    {
        cout << 0 << endl;
        return 0;
    }

    g.printAllPaths(src, dest);

    if (min_sleep == 1e15)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << min_sleep << endl;
    }

    return 0;
}