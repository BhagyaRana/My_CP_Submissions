// OPTIMIZATIONS
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

// HEADERS AND NAMESPACE
#include <bits/stdc++.h>
using namespace std;

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

// to be used with algorithms that processes a container
// Eg: find(all(c),42)
#define all(x) (x).begin(), (x).end()  //Forward traversal

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

// All Functions Here

ll power(ll a, ll b)
{
    ll result = 1;
    while (b)
    {
        if (b % 2)
            result *= a;
        a *= a;
        b /= 2;
    }
    return result;
}

// // Return Prime Factors
vi factorize(int n)
{
    vi factors;
    for (int i = 2; i < sqrt(n) + 1; i++)
    {
        if (n % i == 0)
        {
            int pwr = 0;
            while (n % i == 0)
            {
                pwr++;
                // Integer Division
                n = n / i;
            }
            factors.push_back(power(i, pwr));
        }
    }
    // n is Prime
    if (n != 1)
    {
        factors.push_back(n);
    }
    return factors;
}

ll sum(vi a)
{
    ll ans = 0;
    for (auto x : a)
    {
        ans += x;
    }
    return ans;
}

ll fx(ll pos, vi &arr, vi &factors)
{
    if (pos == factors.size())
    {
        return sum(arr);
    }

    ll ans = 1e9;
    ll sz = arr.size();

    for (ll i = 0; i < sz; i++)
    {
        arr[i] *= factors[pos];
        ans = min(ans, fx(pos + 1, arr, factors));
        arr[i] /= factors[pos];
    }
    return ans;
}

void solve()
{
    int k, x;
    cin >> k >> x;
    
    vi fac = factorize(x);
    ll sz = fac.size();
    if (sz <= k)
    {
        ll ans = 0;
        ans = sum(fac);
        cout << ans + k - sz << endl;
    }
    else
    {

        vi arr(k, 1);
        ll pos = 0;
        ll ans = fx(pos, arr, fac);
        cout << ans << endl;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // b_v_r();
    w(t)
    {
        solve();
    }

    return 0;
}
