#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<int> a;
int m;
ll cnt;
ll dp[20][10];
ll dfs(ll i, ll j, ll k)
{
    if (i == m)
        return 1;
    ll ans = 0;
    for (ll ind = 0; ind <= 10; ind++)
    {
        if (ind * k < a[i])
            ans += pow(cnt, m - 1 - i);
        else if (ind * k == a[i])
            ans += dfs(i + 1, a[i], k);
        else
            break;
        //cout<<ind*k<<" dp "<<ans<<endl;
    }
    return ans;
}
ll f(ll n, ll k)
{
    if (k == 1)
        cnt = 10;
    else if (k == 2)
        cnt = 5;
    else if (k < 5)
        cnt = 10 / k + 1;
    else if (k >= 5)
        cnt = 2;
    a.clear();
    while (n)
    {
        a.push_back(n % 10);
        n /= 10;
    }

    reverse(a.begin(), a.end());

    m = a.size();
    ll ans = 0;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= 10; i++)
    {
        if (i * k < a[0])
            ans += pow(cnt, m - 1);
        else if (i * k == a[0])
            ans += dfs(1, a[0], k);
        else
            break;
        //cout<<i*k<<" "<<ans<<endl;
    }
    return ans;
}
int main()
{
    ll t, i, j, k, n, m, a, b;
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> k;
        //cout<<f(b,k)<<" "<<f(a-1,k)<<endl;
        cout << f(b, k) - f(a - 1, k) << endl;
    }
}