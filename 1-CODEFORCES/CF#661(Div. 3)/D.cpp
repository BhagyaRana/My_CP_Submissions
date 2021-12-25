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
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

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

int main()
{
    b_v_r();

    int n, m;
    cin >> n >> m;
    char a[n+1][m+1];

    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            cin >> a[i][j];
        }
    }

    vector <pair<pair<int, int>, int>> v;
    int mxn = -1;

    for (int i=1;i<=n;i++)
    {
        for (int j=i+1;j<=n;j++)
        {
            // team (i,j) ->
            int sub = 0;
            for (int k=1;k<=m;k++)
            {
                if (a[i][k] == '1' || a[j][k] == '1')
                {
                    sub++;
                }
            }
            v.push_back(make_pair(make_pair(i, j), sub));
            if (sub > mxn)
                mxn = sub;
        }
    }

    int sz = v.size();
    int cnt = 0;
    for (int i=0;i<sz;i++)
    {
        // cout << v[i].second << endl;
        if (v[i].second == mxn)
        {
            cnt++;
        }
    }

    cout << mxn << endl;
    cout << cnt << endl;

    return 0;
}
