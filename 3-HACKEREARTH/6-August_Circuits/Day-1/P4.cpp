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
    cin >> n;

    ll a[n + 1];
    a[0] = 0;
    
    for (ll i = 1; i <= n; i++)
        cin >> a[i];

    ll q;
    cin >> q;
    char type;
    while (q--)
    {
        cin >> type;
        if (type == '1')
        {
            ll l, r, x;
            cin >> l >> r >> x;
            for (ll id = l; id <= r; id++)
            {
                a[id] += x;
            }
        }
        else
        {
            if (type == '2')
            {
                ll l, r, y;
                cin >> l >> r >> y;
                for (ll id = l; id <= r; id++)
                {
                    a[id] *= y;
                }
            }
            else
            {
                ll z;
                cin >> z;
                ll left = -1;
                ll right = -1;
                for (ll id = 1; id <= n; id++)
                {
                    if (a[id] == z)
                    {
                        left = id;
                        break;
                    }
                }
                for (ll id = n; id >= 1; id--)
                {
                    if (a[id] == z)
                    {
                        right = id;
                        break;
                    }
                }

                if (left == -1 || right == -1 || left == right)
                {
                    cout << "-1" << endl;
                    
                }
                else
                {
                    cout << right - left + 1 << endl;
                }
            }
        }
    }

    return 0;
}