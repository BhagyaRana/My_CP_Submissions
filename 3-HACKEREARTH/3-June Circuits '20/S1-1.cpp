//  You are required to find the number of triangles denoted by

//  such that:

//     The triangle is formed by joining only the white-colored vertices of the polygon.
//     The triangle shares at least one side with the polygon.

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

int main()
{
    b_v_r();
    w(t)
    {
        ll n, b1, b2;
        cin >> n >> b1 >> b2;
        ll ans = 0LL;
        ll diff = min(abs(b1 - b2), abs(n - abs(b1 - b2)));
        if (diff == 1)
        {
            ans = (n * n) - (8 * n) + 16;
        }
        else
        {
            if (diff == 2)
            {
                ans = (n * n) - (9 * n) + 21;
            }
            else
            {
                if (diff > 2)
                    ans = (n * n) - (9 * n) + 22;
            }
        }
        cout << ans << endl;
    }

    return 0;
}