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
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int main()
{
    b_v_r();
    ll n;
    w(t)
    {
        cin >> n;

        string s;
        int a[n + 1];

        cin >> s;

        for (int i = 1; i <= n; i++)
        {
            a[i] = (int)(s[i - 1] - '0');
        }

        int prefix[n + 1];
        prefix[0] = 0;
        prefix[1] = a[1];
        for (int i = 2; i <= n; i++)
        {
            prefix[i] = a[i] + prefix[i - 1];
        }

        ll cnt = 0;
        map<int,int> mp;
        mp[0]++;

        for (int r = 1; r <= n; r++)
        {
            cnt += mp[prefix[r]-r];
            ++mp[prefix[r]-r];
        }
        cout << cnt << endl;
    }

    return 0;
}
