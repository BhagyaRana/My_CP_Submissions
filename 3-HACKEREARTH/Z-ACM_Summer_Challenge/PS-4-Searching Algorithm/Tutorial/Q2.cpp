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
    w(t)
    {
        int n;
        cin >> n;
        mk(arr, n + 1, int);
        mk(pre, n + 1, int);

        int i = 0, j;
        rep(i, n)
        {
            cin >> arr[i];
        }
        pre[0] = arr[0];
        for (int k = 1; k < n; k++)
        {
            if (arr[k] > pre[k - 1])
                pre[k] = arr[k];
            else
            {
                pre[k] = pre[k-1];
            }
            
        }
        
        // for (int k = 0; k < n; k++)
        // {
        //     cout<<"pre["<<k<<"] = "<<pre[k] << endl;
        // }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            // int cnt = 0;
            if ((arr[i] < pre[i]))
            {
                int cnt = 0;
                for (j = i - 1; j >= 0; j--)
                {

                    if (arr[j] > arr[i])
                        cnt++;
                }
                ans += cnt;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
