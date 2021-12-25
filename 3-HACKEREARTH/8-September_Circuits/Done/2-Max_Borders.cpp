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
    ll t, n, m, i, j, k;

    cin >> t;
    while (t--)
    {
        // row = n & columns = m
        cin >> n >> m;

        // top and bottom border added
        char mat[n + 2][m + 2];

        for (j = 0; j <= m + 1; j++)
        {
            mat[0][j] = (char)'.';
            mat[n + 1][j] = (char)'.';
        }

        // left and right border added
        for (i = 0; i <= n + 1; i++)
        {
            mat[i][0] = (char)'.';
            mat[i][m + 1] = (char)'.';
        }

        // Input for Inner Table Taken
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= m; j++)
            {
                cin >> mat[i][j];
            }
        }

        vector<ll> border;
        //Horizontal Border
        ll b1 = 0, b2 = 0;
        char ch1, ch2;
        ll c1, c2;
        for (i = 0; i <= n; i++)
        {
            //compare row i & i+1
            for (j = 1; j <= m; j++)
            {
                ch1 = mat[i][j];
                ch2 = mat[i + 1][j];
                if (ch1 == '.' && ch2 == '#')
                {
                    c1 = j;
                    b1 = 0;
                    while (ch1 == '.' && ch2 == '#')
                    {
                        b1++;
                        c1++;
                        ch1 = mat[i][c1];
                        ch2 = mat[i + 1][c1];
                    }
                    border.push_back(b1);
                }
                else
                {
                    if (ch1 == '#' && ch2 == '.')
                    {
                        c2 = j;
                        b2 = 0;
                        while (ch1 == '#' && ch2 == '.')
                        {
                            b2++;
                            c2++;
                            ch1 = mat[i][c2];
                            ch2 = mat[i + 1][c2];
                        }
                        border.push_back(b2);
                    }
                    else
                    {
                        continue;
                    }
                }
            }
        }

        //Vertical Border
        ll h1 = 0, h2 = 0;
        // char ch1, ch2;
        ll d1, d2;
        for (j = 0; j <= m; j++)
        {
            //compare column j & j+1
            for (i = 1; i <= n; i++)
            {
                ch1 = mat[i][j];
                ch2 = mat[i][j + 1];
                if (ch1 == '.' && ch2 == '#')
                {
                    d1 = i;
                    h1 = 0;
                    while (ch1 == '.' && ch2 == '#')
                    {
                        h1++;
                        d1++;
                        ch1 = mat[d1][j];
                        ch2 = mat[d1][j + 1];
                    }
                    border.push_back(h1);
                }
                else
                {
                    if (ch1 == '#' && ch2 == '.')
                    {
                        d2 = i;
                        h2 = 0;
                        while (ch1 == '#' && ch2 == '.')
                        {
                            h2++;
                            d2++;
                            ch1 = mat[d2][j];
                            ch2 = mat[d2][j + 1];
                        }
                        border.push_back(h2);
                    }
                    else
                    {
                        continue;
                    }
                }
            }
        }

        ll mxn = -1;

        for (auto ele : border)
        {
            if (ele > mxn)
                mxn = ele;
        }

        cout << mxn << endl;
    }

    return 0;
}