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
#define MAXN 105
int n, m;
int a[MAXN][MAXN];
string s;
// All Functions Here
void solve()
{
    cin >> n >> m;
    vector<vi> ans;
    for0(i, n)
    {
        cin >> s;
        for0(j, m)
        {
            a[i][j] = s[j] - '0';
        }
    }

    for0(i, n - 1)
    {
        for0(j, m - 1)
        {
            int sum = a[i][j] + a[i][j + 1] + a[i + 1][j] + a[i + 1][j + 1];
            if (sum == 0)
            {
                continue;
            }
            else if (sum == 1)
            {
                // 4 CASES
                // Make all 4 cells Zero in 3 Steps
                if (a[i][j] == 1)
                {
                    ans.push_back({i, j, i, j + 1, i + 1, j + 1});
                    ans.push_back({i, j, i + 1, j, i + 1, j + 1});
                    ans.push_back({i, j, i + 1, j, i, j + 1});
                }
                else if (a[i][j + 1] == 1)
                {
                    ans.push_back({i, j, i + 1, j, i, j + 1});
                    ans.push_back({i, j + 1, i + 1, j + 1, i + 1, j});
                    ans.push_back({i, j, i, j + 1, i + 1, j + 1});
                }
                else if (a[i + 1][j] == 1)
                {
                    ans.push_back({i, j + 1, i + 1, j + 1, i + 1, j});
                    ans.push_back({i, j, i + 1, j, i + 1, j + 1});
                    ans.push_back({i, j, i + 1, j, i, j + 1});
                }
                else if (a[i + 1][j + 1] == 1)
                {
                    ans.push_back({i, j, i + 1, j, i + 1, j + 1});
                    ans.push_back({i, j + 1, i + 1, j + 1, i + 1, j});
                    ans.push_back({i, j, i, j + 1, i + 1, j + 1});
                }
            }
            else if (sum == 2)
            {
                // 6 CASES
                // Make all 4 cells Zero in 2 Steps
                if (a[i][j] == 1 && a[i][j + 1] == 1)
                {
                    ans.push_back({i, j + 1, i + 1, j + 1, i + 1, j});
                    ans.push_back({i, j, i + 1, j, i + 1, j + 1});
                }
                else if (a[i][j + 1] == 1 && a[i + 1][j + 1] == 1)
                {
                    ans.push_back({i, j, i + 1, j, i, j + 1});
                    ans.push_back({i, j, i + 1, j, i + 1, j + 1});
                }
                else if (a[i + 1][j] == 1 && a[i + 1][j + 1] == 1)
                {
                    ans.push_back({i, j, i + 1, j, i, j + 1});
                    ans.push_back({i, j, i, j + 1, i + 1, j + 1});
                }
                else if (a[i][j] == 1 && a[i + 1][j] == 1)
                {
                    ans.push_back({i, j, i, j + 1, i + 1, j + 1});
                    ans.push_back({i, j + 1, i + 1, j + 1, i + 1, j});
                }
                else if (a[i][j] == 1 && a[i + 1][j + 1] == 1)
                {
                    ans.push_back({i, j, i + 1, j, i, j + 1});
                    ans.push_back({i, j + 1, i + 1, j + 1, i + 1, j});
                }
                else if (a[i + 1][j] == 1 && a[i][j + 1] == 1)
                {
                    ans.push_back({i, j, i, j + 1, i + 1, j + 1});
                    ans.push_back({i, j, i + 1, j, i + 1, j + 1});
                }
            }
            else if (sum == 3)
            {
                // 4 CASES
                // Make all 4 cells Zero in 1 Steps
                if (a[i][j] == 0)
                {
                    ans.push_back({i, j + 1, i + 1, j + 1, i + 1, j});
                }
                else if (a[i][j + 1] == 0)
                {
                    ans.push_back({i, j, i + 1, j, i + 1, j + 1});
                }
                else if (a[i + 1][j + 1] == 0)
                {
                    ans.push_back({i, j, i + 1, j, i, j + 1});
                }
                else if (a[i + 1][j] == 0)
                {
                    ans.push_back({i, j, i, j + 1, i + 1, j + 1});
                }
            }
            else if (sum == 4)
            {
                ans.push_back({i, j + 1, i + 1, j, i + 1, j + 1});
                ans.push_back({i, j, i + 1, j, i + 1, j + 1});
                ans.push_back({i, j, i, j + 1, i + 1, j + 1});
                ans.push_back({i, j, i, j + 1, i + 1, j});
            }
            a[i][j] = a[i + 1][j] = a[i][j + 1] = a[i + 1][j + 1] = 0;
        }
    }
    cout << ans.size() << endl;
    // If you use Auto inside Auto -> Pass by Reference
    for (auto &v : ans)
    {
        for (auto el : v)
        {
            cout << el + 1 << " ";
        }
        cout << endl;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // b_v_r();
    w(t)
    {
        solve();
    }

    return 0;
}