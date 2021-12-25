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

    w(t)
    {
        int i, j, qtype;

        int n; //Number of Lights
        int m; //Number of Days

        cin >> n >> m;

        //cfig[0][0.1.2...n] = 000000000 <- Initial State
        map<bool, vector<bool>> cfig;
        map<int, vector<int>> pre;

        vector<vector<bool>> cfig(m + 1, vector<bool>(n + 1, 0));
        // memset(cfig, 0, sizeof(cfig));

        vector<vector<int>> pre(m + 1, vector<int>(n + 1, 0));
        // memset(pre, 0, sizeof(pre));

        int low, rig, a, b;

        int q1cnt = 0;

        int q3ans = 0;

        for (i = 1; i <= m; i++)
        {
            //on ith day
            cin >> qtype;
            for (j = 1; j <= n; j++)
            {
                cfig[i][j] = cfig[i - 1][j];
                pre[i][j] = pre[i - 1][j] + cfig[i][j];
            }

            if (qtype == 1)
            {

                // flip the bits from l to r
                cin >> low >> rig;
                bool f = true;
                for (j = low; j <= rig; j++)
                {
                    if (cfig[i - 1][j] == 1)
                    {
                        cfig[i][j] = 0;
                    }
                    else
                    {
                        cfig[i][j] = 1;
                    }

                    if (f && (cfig[i][j] == 1))
                    {
                        q3ans = i;
                        f = false;
                    }
                    pre[i][j] = pre[i - 1][j] + cfig[i][j];
                }

                q1cnt++;
            }
            else
            {
                if (qtype == 2)
                {

                    cin >> a >> b >> low >> rig;

                    int lightcnt = 0;
                    int minlight = rig;

                    bool flag = true;
                    for (j = low; j <= rig; j++)
                    {
                        if ((pre[b][j] - pre[a - 1][j]) & 1)
                        {
                            lightcnt++;
                            if (flag && (j < minlight))
                            {
                                minlight = j;
                                flag = false;
                            }
                        }
                    }

                    if (lightcnt != 0)
                        cout << lightcnt << " " << minlight << endl;
                    else
                    {
                        cout << "0 0" << endl;
                    }
                }
                else
                {
                    if (qtype == 3)
                    {
                        //lexicographically largest state
                        if (q1cnt == 0)
                        {
                            cout << "0" << endl;
                        }
                        else
                        {
                            cout << q3ans << endl;
                        }
                    }
                }
            }
            // cout << "Day " << i << " : ";
            // for (int tmp = 1; tmp <= n; tmp++)
            // {
            //     if (cfig[i][tmp] == 1)
            //         cout << 1;
            //     else
            //     {
            //         cout << 0;
            //     }
            // }
            // cout << endl;
        }
    }

    return 0;
}