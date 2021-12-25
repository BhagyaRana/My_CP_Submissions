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

int mat[1002][1002];
int dp[1002][1002];

bool check2(int n, int m, int mat[][1002])
{
    // if (mat[1][1] == 1)
    // {
    //     return false;
    // }
    if (mat[1][2] == 1 && mat[2][1] == 1)
    {
        return false;
    }
    // if (mat[n][m] == 1)
    // {
    //     return false;
    // }
    if (mat[n][m - 1] == 1 && mat[n - 1][m] == 1)
    {
        return false;
    }
    for (int i = 1; i <= n; i++)
    {
        if (mat[i][1] == 0)
            dp[i][1] = 1;
        else
            break;
    }
    for (int i = 1; i <= m; i++)
    {
        if (mat[1][i] == 0)
            dp[1][i] = 1;
        else
            break;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= m; j++)
        {
            if (mat[i][j] != 1)
                dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
        }
    }
    if (dp[n][m] >= 1)
    {
        // cout << dp[n][m] << endl;
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    b_v_r();
    int n, m;
    cin >> n >> m;
    // row 1,col 1 ... col m
    // .
    // .
    // row n
    memset(mat, 0, sizeof(mat));

    bool ans[n + 1][m + 1];
    memset(ans, -1, sizeof(ans));

    char ch;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> ch;
            if (ch == '.')
            {
                mat[i][j] = 0;
            }
            else
            {
                if (ch == '#')
                {
                    mat[i][j] = 1;
                }
            }
        }
    }
    //  for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=m;j++)
    //     {
    //         cout << mat[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // Task is to Reach from 1,1 to m,n
    bool res;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (mat[i][j] == 0)
            {
                mat[i][j] = 1;
            }
            else
            {
                // mat[i][j] -> 1

                mat[i][j] = 0;
            }

            res = check2(n, m, mat);

            if (res == true)
                ans[i][j] = 1;
            else
            {
                ans[i][j] = 0;
            }

            cout << ans[i][j] << " ";

            memset(dp, 0, sizeof(dp));

            if (mat[i][j] == 0)
            {
                mat[i][j] = 1;
            }
            else
            {
                mat[i][j] = 0;
            }
        }
        cout << endl;
    }

    return 0;
}
