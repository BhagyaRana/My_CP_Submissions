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
    int x;
    cin >> x;
    // Pigeonhole
    if (x > 45)
    {
        cout << "-1" << endl;
        return;
    }

    if (x <= 9)
    {
        cout << x << endl;
        return;
    }
    else if (x <= 17)
    {
        ll ans = 9;
        x -= 9;
        x *= 10;
        ans += x;
        cout << ans << endl;
    }
    else if (x <= 24)
    {
        ll ans = 89;
        x -= 17;
        x *= 100;
        ans += x;
        cout << ans << endl;
    }
    else if (x <= 30)
    {
        ll ans = 789;
        x -= 24;
        x *= 1000;
        ans += x;
        cout << ans << endl;
    }
    else if (x <= 35)
    {
        ll ans = 6789;
        x -= 30;
        x *= 10000;
        ans += x;
        cout << ans << endl;
    }
    else if (x <= 39)
    {
        ll ans = 56789;
        x -= 35;
        x *= 100000;
        ans += x;
        cout << ans << endl;
    }
    else if (x <= 42)
    {
        ll ans = 456789;
        x -= 39;
        x *= 1000000;
        ans += x;
        cout << ans << endl;
    }
    else if (x <= 44)
    {
        ll ans = 3456789;
        x -= 42;
        x *= 10000000;
        ans += x;
        cout << ans << endl;
    }
    else
    {
        // x == 45

        cout << "123456789" << endl;
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
