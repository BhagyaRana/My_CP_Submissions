// OPTIMIZATIONS
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef long long ll;

ll success_add(ll x)
{
    if (x <= 9)
        return x;

    ll t = x, sum = 0;

    while (t)
    {
        sum += (t % 10);
        t /= 10;
    }

    if (sum <= 9)
        return sum;
    else
        return success_add(sum);
}

void solve()
{
    ll a, b;
    string num;

    cin >> num;
    cin >> a >> b;

    ll odd_sum = 0, even_sum = 0;

    for (int i = 0; i < num.length(); i++)
    {
        if (i & 1) // odd
            odd_sum += num[i] - '0';
        else
            even_sum += num[i] - '0';
    }

    ll nxt_num = (b * odd_sum) + (a * even_sum);

    // Perform Successive Addition Unit Single Digit
    ll ans = success_add(nxt_num);

    cout << ans << endl;

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc = 1;
    cin >> tc;
    // If No Test Case, Then Comment it!
    while (tc--)
    {
        solve();
    }

    return 0;
}