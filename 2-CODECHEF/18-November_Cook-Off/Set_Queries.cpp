#include <bits/stdc++.h>
using namespace std;

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

#define all(x) (x).begin(), (x).end() //Forward traversal

// COMMONLY USED TYPES
typedef vector<int> vi;
typedef long long ll;

#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)

#define MAXN 100005

bool vis[MAXN];

vi query(int type, int node)
{
    cout << type << " " << node + 1 << endl;
    vis[node] = true;
    //Take Input from Grader
    int sz;
    cin >> sz;
    vi nbr(sz);
    for0(i, sz)
    {
        cin >> nbr[i];
        nbr[i]--; // O based Indexing
    }
    return nbr;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> deg(n);
    int start = -1;
    for0(i, n)
    {
        cin >> deg[i];
        if (deg[i] >= k)
        {
            start = i;
        }
    }
    // Found A Node Degree >= k
    if (start != -1)
    {
        vi good = query(2, start);
        for (auto node : good)
        {
            vi bad = query(1, node);
            for (auto x : bad)
            {
                vis[x] = true;
            }
        }
    }

    // Part 2 : Select a Random Unvisited Node and Put all its Neighbours in R
    for0(i, n)
    {
        // Node Not Visited
        if (!vis[i])
        {
            // Insert it in S
            vi bad = query(1, i);
            for (auto x : bad)
            {
                vis[x] = true;
            }
        }
    }
    // For Grader to Know That Task has Been Completed
    cout << 3 << endl;

    return 0;
}