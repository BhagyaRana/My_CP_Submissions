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
    int n;
    cin >> n;
    vi a(2 * n);
    for0(i, 2 * n)
    {
        cin >> a[i];
    }
    sort(all(a));
    // -------INPUT-------
    forc(i, 0, (2 * n - 2))
    {
        multiset<int> b;
        for (auto it : a)
            b.insert(it);
        // ith Number
        bool good = true;
        int X = a[2 * n - 1] + a[i];
        vpi ans;
        for0(j, n)
        {
            // Last Element
            int n1 = *prev(b.end());
            b.erase(b.find(n1));
            if (b.find(X - n1) != b.end())
            {
                b.erase(b.find(X - n1));
                ans.pb({X - n1, n1});
                X = n1; // Sorted
            }
            else
            {
                good = false;
                break;
            }
        }
        // Found Answer
        if (good)
        {
            cout << "YES" << endl;
            // Value of X
            cout << ans[0].first + ans[0].second << endl;
            for (auto it : ans)
            {
                cout << it.first << " " << it.second << endl;
            }
            return;
        }
    }
    cout << "NO" << endl;

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
