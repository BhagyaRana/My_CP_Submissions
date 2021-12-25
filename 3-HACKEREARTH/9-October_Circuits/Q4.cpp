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

    ll n;
    cin >> n;

    vll a(n);

    for0(i, n)
    {
        cin >> a[i];
    }

    if (n <= 0)
    {
        cout << 0 << endl;
        return 0;
    }

    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    if (n == 2)
    {
        if (a[0] >= a[1])
        {
            cout << 2 << endl;
            return 0;
        }
        else
        {
            cout << 1 << endl;
            return 0;
        }
    }

    ll t = a[0];
    bool eq = true;
    for (ll i = 1; i < n; i++)
    {
        if (a[i] != t)
        {
            eq = false;
            break;
        }
    }
    if (eq)
    {
        cout << n << endl;
        return 0;
    }

    ll up = 1;
    ll down = 1;
    ll oldu, oldd;
    for (ll i = 1; i < n; i++)
    {
        bool f1 = false;
        bool f2 = false;
        if (a[i] >= a[i - 1])
        {
            f1 = true;
        }
        if (a[i] <= a[i - 1])
        {
            f2 = true;
        }

        if (f1 && f2)
        {
            //a[i - 1] == a[i]
            oldu = up;
            oldd = down;
            up = oldd + 1;
            down = oldu + 1;
        }else if(f1)
        {
            up = down + 1;
        }
        else
        {
            down = up + 1;
        }
    }

    ll mxn = max(up, down);
    if (mxn == up)
    {
        if (up % 2 == 0)
        {
            mxn = down;
        }
    }
    else
    {
        if (down % 2 == 1)
        {
            mxn = up;
        }
    }

    if (mxn > n)
        cout << n << endl;
    else
    {
        cout << mxn << endl;
    }

    return 0;
}