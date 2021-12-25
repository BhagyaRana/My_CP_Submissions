// OPTIMIZATIONS
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

// HEADERS AND NAMESPACE
#include <bits/stdc++.h>
using namespace std;

//CONSTANTS
const int mod = 1000000007;
// const int mod = 998244353;

//LOOPS
// 0 based indexing
#define for0(i, n) for (int i = 0; i < (int)(n); ++i)
// 1 based indexing
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
// closed interver from l to r r inclusive
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)

//SHORT HAND
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end() //Forward traversal

//FIND
// find if a given value is present in a container. Container version.
// Runs in log(n) for set and map
#define present(c, x) ((c).find(x) != (c).end())
//find version works for all containers. This is present in std namespace.
#define cpresent(c, x) (find(all(c), x) != (c).end())

#define endl "\n"

// COMMONLY USED TYPES
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

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

// All Functions Here

// Prints all subsets of arr[0..n-1] with sum 0.
bool check(vll arr, ll x, ll y)
{
    ll n = sz(arr);
    bool subset[n + 1][y + 1];

    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
        subset[i][0] = true;

    // If sum is not 0 and set is empty,
    // then answer is false
    for (int i = 1; i <= y; i++)
        subset[0][i] = false;

    // Fill the subset table in botton up manner
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= y; j++)
        {
            if (j < arr[i-1])
                subset[i][j] = subset[i - 1][j];
            if (j >= arr[i-1])
                subset[i][j] = subset[i - 1][j] || subset[i - 1][j - arr[i-1]];
        }
    }

    bool flag = false;

    forc(i, x, y)
    {
        if (subset[n][i] == true)
        {
            flag = true;
            return flag;
        }
    }
    return flag;
}

void solve()
{
    ll n;
    ll x, y;

    cin >> n >> x >> y;

    vll a(n, 0);
    vll pre(n, 0);
    ll sum = 0;

    for0(i, n)
    {
        cin >> a[i];
        sum += a[i];
        if(i>=1)
            pre[i] = pre[i - 1] + a[i];
        else
        {
            pre[i] = a[i];
        }
    }

    x = min(x, y);
    y = max(x, y);

    if (sum < x)
    {
        cout << "-1" << endl;
        return;
    }
    else
    {
        if (check(a, x, y) == false)
        {
            cout << "-1" << endl;
            return;
        }

        for0(i, n)
        {
            if (pre[i] >= x && pre[i] <= y)
            {
                cout << "0" << endl;
                return;
            }
        }

        bool chk2 = true;
        ll t1, t2;
        for0(i, n)
        {
            t1 = pre[i];
            t1 -= a[i];
            forc(j, i + 1, n-1)
            {
                t2 = t1 + a[j];
                if (t2 >= x && t2 <= y)
                {
                    cout << "1" << endl;
                    return;
                }
            }
        }

        cout << "2" << endl;
        return;
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // b_v_r();
    int tc = 1;
    cin >> tc;
    // If No Test Case, Then Comment it!
    while (tc--)
    {
        solve();
    }

    return 0;
}
