#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll P, a, b, c, x, y;
    cin >> P >> a >> b >> c >> x >> y;

    ll max_chakri = P / (c + (a * y)), anar = 0;
    ll ans = 0;

    for (ll chakri = 0; chakri <= max_chakri; chakri++)
    {
        anar = (P - ((c + (a * y)) * chakri)) / (b + (a * x));
        ans = max(ans, chakri + anar);
    }

    cout << ans << endl;

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc = 1;
    cin >> tc;
    while (tc--)
        solve();
    return 0;
}
