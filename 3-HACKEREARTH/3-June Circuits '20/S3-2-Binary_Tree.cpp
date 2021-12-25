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

ll ans[100002];

int main()
{
    b_v_r();
    ans[0] = 0;
    ans[1] = 0;
    int t;
    for (int i = 2; i <= 100001; i++)
    {
        // i is even or i/2 (parent) is even
        if (i % 2 == 0 || ((int)(i / 2)) % 2 == 0)
        {
            ans[i] = ans[i - 1];
        }
        else
        {
            t = i;
            int link = 0;
            while ((t % 2) != 0)
            {
                link++;
                t /= 2;
            }
            // link - 1 edges
            ans[i] = ans[i - 1] + link - 1;
        }
    }
    // for(int i=1;i<=100;i++)
    // {
    //     cout << "ans [ "<<i<<" ] = "<<ans[i] << endl;
    // }
    int q;
    cin >> q;
    int x;
    while (q--)
    {
        cin >> x;
        cout << ans[x] << endl;
    }

    return 0;
}
