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
void pairsort(ll a[], ll b[], ll n)
{
    vector<pair<ll, ll>> v(n);
    for (ll i = 0; i < n; i++)
    {
        v[i] = make_pair(a[i], b[i]);
    }
    sort(v.begin(), v.end());
    for (ll i = 0; i < n; i++)
    {
        a[i] = v[i].first;
        b[i] = v[i].second;
    }
    return;
}

// All Functions Here
void solve()
{
    // Two Sorted Arrays Size
    ll n, m;
    cin >> n >> m;

    vll a(n + 1, 0);
    for1(i, n)
    {
        cin >> a[i];
    }

    vll b(m + 1, 0);
    for1(i, m)
    {
        cin >> b[i];
    }

    ll lx, ly;
    //xth Largest & yth Largest
    cin >> lx >> ly;

    //////////

    vector<pair<int, pair<int, int>>> vec;

    vll c;
    ll x;
    for1(i, n)
    {
        forc(j, 1, m)
        {
            x = a[i] + b[j];
            c.emplace_back(x);
            // mp.insert({x, {i, j}});
            vec.pb({x, {i, j}});
        }
    }

    sort(all(vec));

    ll sz2 = vec.size();

    // for (int i = 0; i < sz2; i++)
    // {
    //     auto p1 = vec[i].second;
    //     cout << vec[i].first << " " << p1.first << " " << p1.second << endl;
    // }

    sort(all(c));

    ll sz = c.size();
    // watch(sz);
    ll lowl = c[lx - 1];
    ll highl = c[ly - 1];
    // watch2(lowl, highl);
    // swap(lowl,highl);
    vector<pair<int, int>> ans;

    for (int i = 0; i < sz2; i++)
    {
        auto p1 = vec[i].second;
        // cout << vec[i].first << " " << p1.first << " " << p1.second << endl;
        if (vec[i].first > lowl && vec[i].first < highl)
        {
            ans.pb({p1.first, p1.second});
        }
    }

    ll n1 = ans.size();
    cout << ans.size() << endl;
    sort(all(ans));
    for (int i = 0; i < n1; i++)
    {
        cout << "(" << ans[i].first << "," << ans[i].second << ") ";
    }
    cout << endl;

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    b_v_r();
    int tc = 1;
    // cin >> tc;
    // If No Test Case, Then Comment it!
    while (tc--)
    {
        solve();
    }

    return 0;
}
