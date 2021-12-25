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
    int n, m;
    cin >> n >> m;
    mk(arr, n, int);
    int i = 0;
    rep(i, n)
    {
        cin >> arr[i];
    }
    sort(arr, arr + (sizeof(arr) / sizeof(arr[0])));
    int count = 0;
    int t;
    for (t = 1; count < m; t++)
    {
        int j = 0;
        while (t % arr[j] == 0 && (j < n))
        {
            count++;
            j++;
        }
        // count += (t / arr[j]);
        cout << "Count :" << count << endl;
        cout << "t : " << t << endl;
    }
    cout << t - 1 << endl;

    return 0;
}
