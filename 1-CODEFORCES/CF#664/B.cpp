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

auto random_address = [] { char *p = new char; delete p; return (uint64_t) p; };
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1));

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
    int n, m, sx, sy;

    cin >> n >> m >> sx >> sy;

    bool vis[n + 1][m + 1] = {false};

    cout << sx << " " << sy << endl;
    vis[sx][sy] = true;

    for (int j = m; j >= 1; j--)
    {
        if (!vis[sx][j])
        {
            cout << sx << " " << j << endl;
            vis[sx][j] = true;
        }
    }

    int cnt = 0;
    for (int col = 1; col <= m; col++)
    {
        if (cnt % 2 == 0)
        {
            for (int row = 1; row <= n; row++)
            {
                if (!vis[row][col])
                {
                    cout << row << " " << col << endl;
                    vis[row][col] = true;
                }
            }
        }
        else
        {
            for (int row = n; row >= 1; row--)
            {
                if (!vis[row][col])
                {
                    cout << row << " " << col << endl;
                    vis[row][col] = true;
                }
            }
        }
        cnt++;
    }

    return 0;
}
