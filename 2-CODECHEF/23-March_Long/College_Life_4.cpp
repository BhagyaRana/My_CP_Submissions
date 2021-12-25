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

void solve()
{
    ll n, e, h, a, b, c, k, r;
    cin >> n >> e >> h >> a >> b >> c;

    ll t = e + h - (2 * n);

    if ((t < 0) || ((t + (e - n)) < 0))
    {
        cout << "-1" << endl;
        return;
    }

    ll lmt = min(e, h), ans = 1e18, gans;

    forc(i, 0, lmt)
    {
        gans = 0;

        if (i > n)
            break;
        else if (i == n)
            gans += (c * i);
        else
        {
            gans += (c * i);
            if (a <= b)
            {
                ll n1 = (e - i) / 2;
                ll n2 = (h - i) / 3;
                if (n1 >= (n - i))
                {
                    gans += (n - i) * a;
                }
                else
                {
                    gans += n1 * a;
                    if (n1 + n2 + i < n)
                        gans = 1e18;
                    else
                        gans += (n - i - n1) * b;
                }
            }
            else
            {
                ll n1 = (e - i) / 2;
                ll n2 = (h - i) / 3;
                if (n2 >= (n - i))
                {
                    gans += (n - i) * b;
                }
                else
                {
                    gans += n2 * b;
                    if (n1 + n2 + i < n)
                        gans = 1e18;
                    else
                        gans += (n - i - n2) * a;
                }
            }
        }
        ans = min(ans, gans);
    }

    if (ans != (ll)1e18)
    {
        cout << ans << endl;
    }
    else
    {
        cout << "-1" << endl;
    }
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
