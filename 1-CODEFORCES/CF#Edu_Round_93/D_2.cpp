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
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

const int mxn = 200;
int R, G, B, r[mxn], g[mxn], b[mxn];
int dp[mxn + 1][mxn + 1][mxn + 1];

int main()
{
    b_v_r();

    cin >> R >> G >> B;
    for (int i = 0; i < R; ++i)
        cin >> r[i];
    for (int i = 0; i < G; ++i)
        cin >> g[i];
    for (int i = 0; i < B; ++i)
        cin >> b[i];

    sort(r, r + R);
    sort(g, g + G);
    sort(b, b + B);

    for (int i = 0; i <= R; ++i)
    {
        for (int j = 0; j <= G; ++j)
        {
            for (int k = 0; k <= B; ++k)
            {
                // Red and Green Chosen
                if (i && j) 
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + r[i - 1] * g[j - 1]);
                
                // Red and Blue Chosen
                if (i && k)
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + r[i - 1] * b[k - 1]);

                //Green and Blue Chosen
                if (k && j)
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1] + g[j - 1] * b[k - 1]);
            }
        }
    }

    cout << dp[R][G][B];

    return 0;
}
