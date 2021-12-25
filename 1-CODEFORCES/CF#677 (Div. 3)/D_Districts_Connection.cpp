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
    // b_v_r();
    w(t)
    {
        ll n;
        cin >> n;

        ll a[n + 1] = {0};
        bool vis[n + 1] = {false};
        vis[0] = true;

        for1(i, n)
        {
            cin >> a[i];
        }

        ll t = a[1];

        bool f = true;

        for (int i = 2; i <= n; i++)
        {
            if (a[i] != t)
            {
                f = false;
                break;
            }
        }

        if (f)
        {
            cout << "NO" << endl;
            continue;
        }

        vector<pair<int, int>> mp1;

        bool fg = false;
        ll cnt = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if ((a[i] != a[j]) && !(vis[i]&&vis[j]))
                {
                    mp1.pb(mp(i, j));
                    vis[i] = true;
                    vis[j] = true;

                    cnt++;

                    if (cnt == n - 1)
                    {
                        for (int k = 1; k <= n; k++)
                        {
                            if (vis[k] == false)
                            {
                                cout << "NO" << endl;
                                fg = true;
                                break;
                            }
                        }

                        if (!fg)
                        {
                            cout << "YES" << endl;
                            // cout << mp1.size() << endl;
                            for (auto p : mp1)
                            {
                                cout << p.first << " " << p.second << endl;
                            }
                            fg = true;
                        }
                        break;
                    }

                }
            }
            if(fg)
            {
                break;
            }
        }

        if(mp1.size()!=(n-1) && fg==false)
        {
            cout << "NO" << endl;
        }

        
    }

    return 0;
}
