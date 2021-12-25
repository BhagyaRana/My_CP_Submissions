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
    ll n, q, i, j, k, type;
    ll l, r, x;
    cin >> n >> q;
    ll a[n + 1] = {0};
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    while (q--)
    {
        cin >> type;
        if (type == 1)
        {
            //1 l r x, for each i ∈ [l, r] replace ai with the value of x.
            cin >> l >> r >> x;
            for (j = l; j <= r; j++)
            {
                a[j] = x;
            }
        }
        else
        {
            if (type == 2)
            {
                //2 l r x, for each i ∈ [l, r] replace ai with the value of the gcd(ai, x) function.
                cin >> l >> r >> x;
                for (j = l; j <= r; j++)
                {
                    a[j] = gcd(a[j], x);
                }
            }
            else
            {
                if (type == 3)
                {
                    //3 l r, print the value of max ai, l ≤ i ≤ r.
                    cin >> l >> r;
                    ll max = a[l];
                    for (k = l; k <= r; k++)
                    {
                        if (a[k] > max)
                            max = a[k];
                    }
                    cout << max << endl;
                }
                else
                {
                    if (type == 4)
                    {
                        cin >> l >> r;
                        ll sum = 0;
                        for (k = l; k <= r; k++)
                        {
                            sum += a[k];
                        }
                        cout << sum << endl;
                    }
                }
            }
        }
    }

    return 0;
}