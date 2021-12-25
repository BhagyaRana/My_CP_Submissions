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
typedef unsigned long long ll;
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
    int i, j, k;

    ll pow2[33];
    pow2[0] = 1;
    for (int i = 1; i < 33; i++)
    {
        pow2[i] = 2 * pow2[i - 1];
        // watch(pow2[i]);
    }

    int n;
    cin >> n;

    ll a[n + 1] = {0};

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<vector<ll>> cost;
    vector<vector<int>> pre;
    // ll cost[sz][32];
    // ll pre[sz][32];

    vector<ll> v1;
    vector<int> p1;
    for (int k = 0; k < 32; k++)
    {
        v1.emplace_back(0);
        p1.emplace_back(0);
    }

    cost.emplace_back(v1);
    pre.emplace_back(p1);

    for (i = 1; i <= n; i++)
    {
        bitset<32> b(a[i]);
        vector<ll> v1;
        vector<int> p1;

        for (k = 0; k < 32; k++)
        {
            if (b[k] == 0)
            {

                if (k == 0)
                {
                    v1.emplace_back(1);
                    // cost[k][i] = 1; // 2 ^ 0
                }
                else
                {
                    for (j = k - 1; j >= 0; j--)
                    {
                        if (b[j] == 0)
                        {
                            v1.emplace_back(pow2[j + 1]);
                            break;
                            // cost[k][i] = pow2[j + 1]; // 2^j+1
                        }
                    }
                }

                p1.emplace_back(1);
            }
            else
            {
                v1.emplace_back(0);
                p1.emplace_back(0);
            }
        }
        cost.emplace_back(v1);
        pre.emplace_back(p1);
    }

    for (i = 1; i <= n; i++)
    {
        for (int k = 0; k < 31; k++)
        {
            cost[i][k] += cost[i - 1][k];
            pre[i][k] += pre[i - 1][k];
        }
    }

    // for (i = 0; i <= n; i++)
    // {
    //     cout << "Number : " << i << endl;
    //     for (int k = 0; k < 31; k++)
    //     {
    //         cout << "k : " << k << endl;
    //         cout << cost[i][k] << endl;
    //     }
    // }

    int q;
    int l, r;

    cin >> q;
    while (q--)
    {
        cin >> l >> r;
    
        bool f = true;
        for (int k = 0; k < 31; k++)
        {
            if ((pre[r][k] - pre[l - 1][k]) == 0)
            {
                cout << 0 << endl;
                f = false;
                break;
            }
        }

        if (f)
        {
            ll cst = 1e9;
            ll tmp = 0;
            
            for (k = 0; k < 31; k++)
            {
                tmp = cost[r][k] - cost[l-1][k];
                if (tmp < cst)
                    cst = tmp;
            }
            cout << cst << endl;
        }
    }

    return 0;
}