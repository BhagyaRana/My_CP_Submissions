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
    //Adj List
    unordered_map<string, list<pair<string, int>>> l;
    // Hash Map 
public:
    void addEdge(string x, string y, bool bidir, int wt)
    {
        l[x].push_back(make_pair(y, wt));
        if (bidir)
        {
            l[y].push_back(make_pair(x, wt));
        }
    }

    void printAdjList()
    {
        //Iterate over all keys in the map
        for (auto p :l)
        {
            string city = p.first;
            list<pair<string, int> > nbrs = p.second;
            cout << city << " -> ";
            for (auto nbr:nbrs)
            {
                string dest = nbr.first;
                int dist = nbr.second;

                cout <<"(" <<dest << ", "<< dist << ") , ";
            }
            cout << endl;

        }
    }

};

int main()
{
    b_v_r();

    Graph g;

    g.addEdge("A", "B", true, 20);
    g.addEdge("B", "D", true, 40);
    g.addEdge("A", "C", true, 10);
    g.addEdge("C", "D", true, 40);
    g.addEdge("A", "D", false, 50);

    g.printAdjList();


    return 0;
}
