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
bool mindiff(vll arr, ll arrsum, ll k)
{
    if (arr.size() == 0)
    {
        return false;
    }

    ll sum = arrsum / 2;

    ll sz = arr.size();

    bool mat[sz + 1][sum + 1] = {0};

    for (ll i = 0; i <= sz; i++)
    {
        mat[i][0] = true;
    }

    for (ll j = 1; j <= sum; j++)
    {
        mat[0][j] = false;
    }

    for (ll i = 1; i <= sz; i++)
    {
        for (ll j = 1; j <= sum; j++)
        {
            // If i'th element is excluded
            mat[i][j] = mat[i - 1][j];
            // If i'th element is included
            if (j >= arr[i - 1])
                mat[i][j] |= mat[i - 1][j - arr[i - 1]];
        }
    }

    ll lastrow = sz;
    ll fps = -1;

    for (ll j = sum; j >= 0; j--)
    {
        if (mat[lastrow][j])
        {
            fps = j;
            break;
        }
    }

    ll sps = arrsum - fps;

    // ll diff = abs(fps - sps);
    ll diff = abs(arrsum - (2 * fps));
    // watch(diff);
    // watch(arrsum);
    // watch2(fps, sps);

    if (fps >= k && sps >= k)
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
    ll n, k;
    cin >> n >> k;
    vll h(n, 0);
    ll hs = 0;

    for0(i, n)
    {
        cin >> h[i];
        hs += h[i];
    }

    if ((hs < (2 * k)) || (n == 1))
    {
        cout << "-1" << endl;
        return;
    }
    else if (hs == (2 * k))
    {
        // Check If It is Possible to Get A Subset of Sum "k"
        ll sz = h.size();
        sort(all(h));

        if (mindiff(h, hs, k))
        {
            cout << n << endl;
            return;
        }
        else
        {
            cout << "-1" << endl;
            return;
        }
    }
    else // hs > 2*k
    {
        // Minimum Answer in Worst Case : 2 Boxes [Both >= k]
        // Get Two Subsets of Minimum Sum "k"
        if (n == 2)
        {
            if (h[0] >= k && h[1] >= k)
            {
                cout << "2" << endl;
                return;
            }
            else
            {
                cout << "-1" << endl;
                return;
            }
        }

        sort(all(h));

        // cout << "HGT" << endl;
        // for (int i = 0; i < n; i++)
        // {
        //     cout << h[i] << " ";
        // }
        // cout << endl;

        vll pre(n, 0);
        pre[n - 1] = h[n - 1];
        for (ll i = n - 2; i >= 0; i--)
        {
            pre[i] = pre[i + 1] + h[i];
        }

        // cout << "PRE" << endl;
        // for (int i = 0; i < n; i++)
        // {
        //     cout << pre[i] << " ";
        // }
        // cout << endl;

        vll arr;
        arr.pb(h[n - 1]);
        ll ans = 1;
        ll i = n - 2;

        while ((pre[i] < (2*k)) && i >= 0)
        {
            arr.pb(h[i]);
            ans++;
            i--;
        }

        for (; i >= 0; i--)
        {
            arr.pb(h[i]);
            ans++;

            if (mindiff(arr, pre[i], k))
            {
                // cout << "here - ";
                cout << ans << endl;
                return;
            }
        }

        // Incase No Answer
        cout << "-1" << endl;
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
