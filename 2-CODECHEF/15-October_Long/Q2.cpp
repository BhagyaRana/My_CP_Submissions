#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define endl "\n"
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
typedef long long ll;
#define mk(arr, n, type) type *arr = new type[n]
const int mod = 1000000007;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

#define watch(x) cout << (#x) << " is : " << (x) << "\n"
#define watch2(x, y) cout << (#x) << " is " << (x) << " and " << (#y) << " is " << (y) << "\n"

void b_v_r()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

// All Functions Here

// All Variables Here

int main()
{
    b_v_r();
    ll n, x, p, k;
    ll i, j;
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n >> x >> p >> k;

        ll a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        // All Input Taken

        // 1 - Sort the Array
        sort(a, a + n);

        ll ans = 0LL;

        // Case 1 : pth position = x
        if (a[p - 1] == x)
        {
            cout << 0 << endl;
        }
        else if (k >= p && a[p - 1] >= x)
        {
            // Case 2 : k >= p && a[p - 1] >= x
            ans = 0;
            for (i = p - 1; i >= 0; i--)
            {
                if (a[i] > x)
                    ans++;
            }
            cout << ans << endl;
        }
        else if (p >= k && a[p - 1] <= x)
        {
            // Case 3 : k <= p && a[p - 1] <= x
            ans = 0;
            for (i = p - 1; i < n; i++)
            {
                if (a[i] < x)
                    ans++;
            }
            cout << ans << endl;
        }
        else
        {
            // Case 4 : p < k && a[p-1] < x OR p > k && a[p-1] > x
            cout << "-1" << endl;
        }
    }

    return 0;
}