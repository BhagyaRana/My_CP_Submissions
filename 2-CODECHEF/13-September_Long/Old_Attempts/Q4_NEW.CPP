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
    ll n;
    w(t)
    {
        cin >> n;
        ll sum = (n * (n + 1)) / 2;
        ll inp = n;
        if (sum & 1)
        {
            cout << "0" << endl;
            continue;
        }
        ll ans = 0;
        ll half = sum / 2;
        ll suffix = 0;
        while (suffix < half)
        {
            suffix += n;
            n--;

            if (suffix == half)
            {
                ans += (n * (n - 1)) / 2 + (((inp - n) * (inp - n - 1)) / 2);
                break;
            }
            ans++;
            if (suffix >= half)
                break;
        }
        cout << ans << endl;
    }

    return 0;
}