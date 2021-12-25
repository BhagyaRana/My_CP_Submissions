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
    ll l, r;
    w(t)
    {
        cin >> l >> r;

        if (r - l == 1)
        {
            cout << "-1 -1" << endl;
            continue;
        }

        ll x = l, y = r;

        ll lcm = (x*y) / (__gcd(x, y));
        // cout << "lcm : " << lcm << endl;

        if (lcm >= l && lcm <= r)
        {
            cout << x << " " << y << endl;
            continue;
        }
        else
        {
            bool flag = true;
            ll xtemp = x;
            ll ytemp = y;
            while (flag)
            {
                ytemp--;
                lcm = (xtemp*ytemp) / (__gcd(xtemp, ytemp));
                if (lcm >= l && lcm <= r)
                {
                    cout << xtemp << " " << ytemp << endl;
                    flag = false;
                    break;
                }
            }
            while (flag)
            {
                x++;
                lcm = (x*y) / (__gcd(x, y));
                if (lcm >= l && lcm <= r)
                {
                    cout << x << " " << y << endl;
                    flag = false;
                    break;
                }
            }

            if(flag)
            {
                cout << "-1 -1" << endl;
            }
            else
            {
                continue;
            }
            
        }
    }

    return 0;
}
