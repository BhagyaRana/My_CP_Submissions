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
#define all(x) (x).begin(), (x).end() //Forward traversal
#define rall(x) (x).rbegin, (x).rend() //reverse traversal

//FIND
// find if a given value is present in a container. Container version. 
// Runs in log(n) for set and map
#define present(c,x) ((c).find(x) != (c).end())
//find version works for all containers. This is present in std namespace.
#define cpresent(c,x) (find(all(c),x) != (c).end())

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
typedef map<int,int> mii; 

#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
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
    int n,m;
    cin >> n >> m;
    // m = n-1;
    int in1[n+1]={0};
    int out1[n+1]={0};
    bool vis1[n+1]={false};
    int ans[n+1]={0};
    int u,v;
    for0(i,m)
    {
        cin >> u >> v;
        in1[u]++;
        out1[u]++;
        in1[v]++;
        out1[v]++;
    }
    // cout << "INDEGREE1" << endl;
    // for(int i=1;i<=n;i++)
    // {
    //     cout << in1[i] << " ";
    // }
    // cout << endl;
    // cout << "OUTDEGREE1" << endl;
    // for(int i=1;i<=n;i++)
    // {
    //     cout << out1[i] << " ";
    // }
    // cout << endl;

    int in2[n+1]={0};
    int out2[n+1]={0};
    bool vis2[n+1]={false};

    for0(i,m)
    {
        cin >> u >> v;
        in2[u]++;
        out2[u]++;
        in2[v]++;
        out2[v]++;
    }

    // cout << "INDEGREE2" << endl;
    // for(int i=1;i<=n;i++)
    // {
    //     cout << in2[i] << " ";
    // }
    // cout << endl;
    // cout << "OUTDEGREE2" << endl;
    // for(int i=1;i<=n;i++)
    // {
    //     cout << out2[i] << " ";
    // }
    // cout << endl;

    for(int i=n;i>=1;i--)
    {
        // in2[i] out2[i] 
        for(int j=n;j>=1;j--)
        {
            if(vis1[j]==false)
            {
                if((in1[j]==in2[i])&&(out1[j]==out2[i]))
                {
                    // watch2(i,j);
                    ans[i] = j;
                    vis1[j]=true;
                    break;
                }
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
