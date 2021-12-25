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

vi slice1(vi &arr, int X, int Y)
{
    auto start = arr.begin() + X;
    auto end = arr.begin() + Y + 1;
    vi result(Y - X + 1);
    copy(start, end, result.begin());
    return result;
}

const int N = 120;
int posi[N];
int hgt[N];
int a[N];
int n;

void dfs(int st, int end, int oldhgt)
{
    if (st > end)
        return;
    else if (st == end)
    {
        // watch(st);
        // watch(oldhgt);
        hgt[a[st]] = oldhgt;
        return;
    }
    else
    {
        int m1 = 0;
        for (int i = st; i <= end; i++)
        {
            m1 = max(m1, a[i]);
        }

        hgt[m1] = oldhgt;

        int p = posi[m1];
        dfs(st, p - 1, oldhgt + 1);
        dfs(p + 1, end, oldhgt + 1);
    }

    return;
}

void solve()
{
    // int n;
    cin >> n;

    for0(i, 120)
    {
        a[i] = 0;
        hgt[i] = 0;
        posi[i] = 0;
    }

    for0(i, n)
    {
        cin >> a[i];
        posi[a[i]] = i;
    }

    dfs(0, n - 1, 0);

    for0(i, n)
    {
        cout << hgt[a[i]] << " ";
    }
    cout << endl;

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
