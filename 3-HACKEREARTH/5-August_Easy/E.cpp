#pragma GCC optimize("O2")

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

int main()
{
    b_v_r();
    int n, q, i, idx;
    w(t)
    {

        cin >> n;
        ll a[n + 1];
        a[0] = 0;
        for (i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        cin >> q;

        while (q--)
        {
            cin >> idx;
            // bool flag  = true;
            ll sum = 0LL;
            ll max = -1;
            for (i = 1; i <= n; i++)
            {
                if (i != idx)
                {
                    if ((i & idx) == 0)
                    {
                        sum = a[i] + a[idx];
                        if (sum > max)
                        {
                            max = sum;
                        }
                    }
                }
            }
            cout << max << endl;
        }
    }

    return 0;
}
