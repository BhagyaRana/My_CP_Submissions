#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
#include <math.h>
using namespace std;

#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
typedef long long ll;

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

// All Variables Here
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
ll inverse(ll a, ll p)
{
    return power(a, p - 2);
}

int main()
{
    b_v_r();
    ll k;
    cin >> k;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, i;
        cin >> n;
        if (n == 1)
        {
            cout << 1 << endl;
            cout << 1 << endl;
            continue;
        }

        ll asum = 0, bsum = 0;

        vector<int> v(n + 1, 0);

        asum += power(n, k);

        i = n - 1;

        while (i > 0)
        {
            while (bsum < asum)
            {
                bsum += power(i, k);
                v[i] = 1;

                i--;
                if (i <= 0)
                {
                    break;
                }
            }
            asum += power(i, k);
            i--;
        }

        cout << abs(bsum - asum) << endl;
        // cout << abs(b - a) << endl;

        for (int i = 1; i <= n; i++)
        {
            cout << v[i];
        }
        cout << endl;
    }

    return 0;
}