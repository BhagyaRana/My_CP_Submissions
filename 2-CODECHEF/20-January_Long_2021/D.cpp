// OPTIMIZATIONS
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

// HEADERS AND NAMESPACE
#include <bits/stdc++.h>
using namespace std;

//CONSTANTS
// const int mod = 1000000007;
const int mod = 998244353;

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

const ll md = 998244353;

inline void add(ll &a, ll b)
{
    a += b;
    if (a >= md)
        a -= md;
}

inline void sub(ll &a, ll b)
{
    a -= b;
    if (a < 0)
        a += md;
}

inline ll mul(ll a, ll b)
{
    return (ll)((long long)a * b % md);
}

inline ll power(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

inline ll inv(ll a)
{
    return power(a, md - 2);
}

void solve()
{
    ll m, n, k;
    cin >> m >> n >> k;
    // m = {1,2}
    if (m == 1)
    {
        vll mem(n + 1, 0);
        ll t1, t2, t3;
        // Subproblem when n==1, k SCC of Size 1 can be Formed in k Ways
        mem[1] = k;

        forc(i, 2, n)
        {
            // (k*mem[i-1])
            t1 = mul(k, mem[i - 1]);
            add(mem[i], t1);
            t2 = power(k, i - 1);
            t3 = mul(t2, k);
            sub(t3, t2);
            // k^(i) - k^(i-1)
            add(mem[i], t3);
        }
        ll p = mem[n];
        // k^(n*m) here m = 1
        ll den = power(k, n);
        ll q = inv(den);
        ll ans = mul(p, q);
        cout << ans << endl;
    }
    else
    {
        // m == 2
        ll p = 1;
        // n*m SCC Components
        add(p, mul(k, mul(n, m)));

        // k ^ (n*m)
        ll den = power(k, n * m);
        ll q = inv(den);
        ll ans = mul(p, q);
        cout << ans << endl;
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // b_v_r();
    int tc = 1;
    // cin >> tc;
    // If No Test Case, Then Comment it!
    while (tc--)
    {
        solve();
    }

    return 0;
}
