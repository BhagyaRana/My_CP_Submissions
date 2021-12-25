#include <bits/stdc++.h>

using namespace std;

#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define endl "\n"
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define rep(i, n) for (i = 0; i < n; ++i)
#define REP(i, k, n) for (i = k; i <= n; ++i)
#define REPR(i, k, n) for (i = k; i >= n; --i)
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

int main()
{
    b_v_r();
    int n, m, k;
    cin >> n >> m >> k;
    ll arr[n][m];
    memset(arr, 0, sizeof(arr[0][0]) * n * m);
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         arr[i][j] = 0;
    //     }
        
    // }
    short int qn;
    while (k--)
    {
        cin >> qn;
        if (qn == 1)
        {
            int r1;
            ll a1;
            cin >> r1 >> a1;
            for (int c = 0; c < m; c++)
            {
                arr[r1 - 1][c] = a1;
            }
        }
        else
        {
            if (qn == 2)
            {
                int c1;
                ll a1;
                cin >> c1 >> a1;
                for (int r = 0; r < n; r++)
                {
                    arr[r][c1 - 1] = a1;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
