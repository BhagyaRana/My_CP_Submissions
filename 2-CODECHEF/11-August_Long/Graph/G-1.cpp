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

class Graph
{
    int V;
    //Array of list
    list <int> *l;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void printAdjList()
    {
        // Iterate over all Vertices
        for (int i=0;i<V;i++)
        {
            cout << "Vertex "<< i << " -> ";
            for (int nbr:l[i])
            {
                cout << nbr <<",";
            }
            cout << endl;
        }
    }

};

int main()
{
    b_v_r();

    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 2);

    g.printAdjList();


    return 0;
}
