#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)

void solve()
{
    ll l, r;
    cin >> l >> r;

    ll l1 = min(l, r);
    ll r1 = max(l, r);

    ll ans = 0;
    for (ll b = 1; b <= sqrt(r) + 1; b++)
    {
        if (b & 1)
        {
            //  ll st = l1 / b;
            ll st = ceil((l1 * 1.0) / b);
            st = max(st, b);
            if (st % 2 == 0)
                st++;

            // ll end = r1 / b;
            ll end = floor((r1 * 1.0) / b);
            if (end % 2 == 0)
                end--;

            if (end >= st)
            {
                ans += ((end - st) / 2) + 1;
            }
        }
        else
        {
            // ll st = l1 / b;
            ll st = ceil((l1 * 1.0) / b);
            st = max(st, b);
            if (st & 1)
                st++;

            // ll end = r1 / b;
            ll end = floor((r1 * 1.0) / b);
            if (end & 1)
                end--;

            if (end >= st)
            {
                ans += ((end - st) / 2) + 1;
            }
        }
    }
    cout << ans << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // If No Test Case, Then Comment it!
    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}