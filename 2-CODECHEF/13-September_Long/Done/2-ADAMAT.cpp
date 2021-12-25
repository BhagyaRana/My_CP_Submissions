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
    int n, i, j, val;
    w(t)
    {
        cin >> n;
        int mat[n + 1][n + 1] = {0};
        ll cnt = 0;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                cin >> mat[i][j];
            }
        }
        int a[n + 1] = {0};
        for (i = 2; i <= n; i++)
        {
            if (mat[1][i] == i)
                a[i] = 1;
        }
        int ans = 0;
        for (int k = n; k >= 2; k--)
        {
            if (a[k] == 1)
            {
                continue;
            }
            else
            {
                ans++;
                a[k] = 1;
                for (int j = k - 1; j >= 2; j--)
                {
                    if (a[j] == 1)
                        a[j] = 0;
                    else
                        a[j] = 1;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}