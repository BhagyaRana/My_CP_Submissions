#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

signed main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m, k;
        cin >> n;

        k = 2;
        m = 3;

        ll a[n];
        for (ll i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a + n);

        ll l = 0;
        ll ans = 0;
        for (ll i = 0; i < n; i++)
        {
            while (a[i] - a[l] > k)
                l++;

            if (i - l < m - 1)
                continue;

            ans += ((i - l) * (i - l - 1)) / 2;
        }

        cout << ans << endl;
    }

    return 0;
}