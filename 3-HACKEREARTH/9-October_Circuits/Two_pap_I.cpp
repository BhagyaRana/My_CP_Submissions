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

// All Functions Here

// All Variables Here

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    b_v_r();

    ll ans = 0;
    ll ans2 = 0;
    ll ans3 = 0;

    // Number of Trees Vertices
    ll n, m;
    cin >> n;

    m = n - 1;
    // n-1 vertices of Tree
    int v, u;
    ll w;
    // weight can be of 10^9

    vector<ii> edge;
    vector<ll> weight;
    int sel = 0;
    for0(i, m)
    {
        // Edge from v to u with weight w
        cin >> v >> u >> w;
        if (n <= 10000)
        {
            edge.pb(mp(v, u));
            weight.pb(w);
        }

        if (sel & 1)
        {
            ans3 ^= w;
        }
        // ans ^= w;
    }

    if (n > 10000)
    {
        cout << ans3 << endl;
        return 0;
    }

    // n-1 edges
    ii p1;
    ii p2;
    bool f1, f2;

    // vector<vector<int>> dis;

    for0(i, n - 1)
    {
        // v -> u with weight w
        // cout << edge[i].first << " " << edge[i].second << " " << weight[i] << endl;
        int cnt = 0;
        // vi tmp;
        for0(j, n - 1)
        {
            if (i != j)
            {
                p1 = edge[i];
                p2 = edge[j];
                f1 = false;
                f2 = false;
                if ((p1.first != p2.first) && (p1.first != p2.second))
                {
                    // x - cor is disjoint
                    f1 = true;
                }
                if ((p1.second != p2.first) && (p1.second != p2.second))
                {
                    // y - cor is disjoint
                    f2 = true;
                }
                if (f1 && f2)
                {
                    // watch2(i, j);
                    // cout << "[" << p1.first << "," << p1.second << "]" << endl;
                    // cout << "[" << p2.first << "," << p2.second << "]" << endl;
                    // cout << "Disjoint hai" << endl;
                    tmp.pb(j);
                    cnt++;
                }
            }
        }

        // dis.pb(tmp);

        if (cnt % 2 == 0)
        {
            ans ^= weight[i];
        }
        else
        {
            ans2 ^= weight[i];
        }
    }

    // int cnt12 = 0;
    // for (auto x : dis)
    // {
    //     cout << cnt12 << " -> ";
    //     for (auto y : x)
    //     {
    //         cout << y << " ";
    //     }
    //     cout << endl;
    //     cnt12++;
    // }

    cout << ans << endl;
    // cout << ans2 << endl;

    return 0;
}
