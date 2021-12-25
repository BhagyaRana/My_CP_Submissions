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
// Is it Valid Point
bool belowline(ll a, ll b, ll c, ll x1, ll y1, ll x2, ll y2)
{
    ll v1 = (a * x1) + (b * y1) + c;
    ll v2 = (a * x2) + (b * y2) + c;

    if (v1 == 0)
    {
        return true;
    }

    if ((v1 * v2) > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solve()
{
    ll n;
    cin >> n;

    vll h(n + 1, 0);

    for1(i, n)
    {
        cin >> h[i];
    }

    ll ans = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 2; j <= n; j++)
        {
            // ax + by + c
            ll a = h[j] - h[i];
            ll b = i - j;
            ll c = ((h[i] * (j - i)) - (i * a));
            bool ok = true;

            for (int k = i + 1; k < j; k++)
            {
                if (!belowline(a, b, c, k, h[k], i, -1))
                {
                    ok = false;
                    break;
                }
            }

            if (ok)
            {
                cout << i << " " << j << " " << j - i << endl;
                ans = max(ans, j - i);
            }
        }
    }
    cout << ans << endl;

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
