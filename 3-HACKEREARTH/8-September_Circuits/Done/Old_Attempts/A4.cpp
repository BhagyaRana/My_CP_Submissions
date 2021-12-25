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
#define MAX 32
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
// All Variables Here

int main()
{
    b_v_r();

    ll n, i, j, k;

    cin >> n;

    ll a[n];

    ll zero[n + 1][MAX] = {0};
    ll pre[n + 1][MAX] = {0};
    ll cost[n + 1][MAX] = {0};

    for (i = 1; i <= n; i++)
    {
        cin >> a[i];

        bitset<32> b(a[i]);

        for (k = 0; k <= 31; k++)
        {
            if (!b[k])
            {
                // cost will come here
                if (k == 0)
                {
                    cost[i][k + 1] = 1;
                }
                else
                {
                    if (b[k] == 0)
                    {
                        cost[i][k + 1] = power(2, k+1);
                    }
                    else
                    {
                        int f = 0;
                        for (j = k - 1; j >= 0; j--)
                        {
                            if (b[j] == 0)
                            {
                                cost[i][k + 1] = power(2, j+1);
                                f = 1;
                                break;
                            }
                        }
                        if (f == 0)
                        {
                            cost[i][k + 1] = 1;
                        }
                    }
                }

                zero[i][k] = 1;
            }
            else
            {
                zero[i][k] = 0;
            }
        }
    }


    

    for (j = 1; j <= n; j++)
    {
        if (j != 0)
        {
            for (k = 0; k < MAX; k++)
            {
                pre[j][k] = zero[j][k] + pre[j - 1][k];
            }
        }
        else
        {
            for (k = 0; k < MAX; k++)
            {
                pre[j][k] = zero[j][k];
            }
        }
    }

    // for (i = 1; i <= n; i++)
    // {
    //     cout << "zero[" << i << "] = ";
    //     for (k = MAX - 1; k > 0; k--)
    //     {
    //         cout << zero[i][k];
    //     }
    //     cout << endl;
    // }

    // for (i = 1; i <= n; i++)
    // {
    //     cout << "pre[" << i << "] = ";
    //     for (k = MAX - 1; k > 0; k--)
    //     {
    //         cout << pre[i][k];
    //     }
    //     cout << endl;
    // }

    ll l, r, size, zrocnt;

    ll q;
    cin >> q;
    while (q--)
    {
        cin >> l >> r;

        size = r - l + 1;

        int flag = 0;

        ll pow = 1;
        ll min_cst = 1e15;

        for (k = 1; k < MAX; k++)
        {
            zrocnt = pre[r][k] - pre[l - 1][k];

            if (zrocnt == 0)
            {
                cout << "0" << endl;
                flag = 1;
                break;
            }

            // if ((zrocnt * pow) < min_cst)
            //     min_cst = (zrocnt * pow);

            // pow *= 2;
        }

        // watch(pow);

        if (flag != 1)
        {
            ll target = 1;

            for (k = 1; k < MAX; k++)
            {
                // zrocnt = pre[r][k] - pre[l - 1][k];
                ll cost1 = 0;

                for (i = l; i <= r; i++)
                {
                    if (zero[i][k] != 0)
                    {
                        cost1 += cost[i][k];
                    }
                }
                // watch(cost);
                if (cost1 < min_cst)
                    min_cst = cost1;
                // pow *= 2;
            }

            cout << min_cst << endl;
            continue;
        }
    }

    return 0;
}