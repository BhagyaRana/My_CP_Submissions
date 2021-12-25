#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
#include <math.h>
using namespace std;

#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
typedef long long ll;

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

// All Variables Here
ll power(ll a, ll b)
{
    ll result = 1;
    while (b)
    {
        if (b % 2)
            result *= a;
        a *= a;
        b /= 2;
    }
    return result;
}
ll inverse(ll a, ll p)
{
    return power(a, p - 2);
}

int main()
{
    b_v_r();
    ll k;
    cin >> k;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if (n == 1)
        {
            cout << 1 << endl;
            cout << 1 << endl;
            continue;
        }

        ll sum = 1;

        if (k == 1)
        {
            sum *= n;
            sum *= (n + 1);
            sum /= 2;
        }
        else
        {
            if (k == 2)
            {
                sum *= n;
                sum *= (n + 1);
                sum /= 2;
                sum *= ((2 * n) + 1);
                sum /= 3;
            }
            else
            {
                if (k == 3)
                {
                    sum *= n;
                    sum *= (n + 1);
                    sum /= 2;
                    sum *= sum;
                }
                else
                {
                    // k == 4
                    sum *= power(n, 5) / (ll)5;
                    sum += power(n, 4) / (ll)2;
                    sum += power(n, 3) / (ll)3;
                    sum -= n / (ll)30;
                }
            }
        }

        vector<int> v(n + 1, 0);
        ll t1 = 0;

        if (sum & 1)
        {
            // cout << "1" << endl;
            // Subset sum = (sum - 1)/2;
            ll subset = (sum + 1) / 2;
            for (int i = n; i >= 1; i--)
            {
                t1 = power(i, k);
                if (t1 > subset)
                {
                    continue;
                }
                else
                {
                    if (t1 == subset)
                    {
                        subset -= t1;
                        v[i] = 1;
                        break;
                    }
                    else
                    {
                        subset -= t1;
                        v[i] = 1;
                    }
                }
            }
            ll a = 0, b = 0;
            for (int i = 1; i <= n; i++)
            {
                if (v[i])
                {
                    b += power(i, k);
                }
                else
                {
                    a += power(i, k);
                }
            }

            cout << n << " -> " << abs(b - a) << endl;
            // cout << abs(b - a) << endl;

            for (int i = 1; i <= n; i++)
            {
                cout << v[i];
            }
            cout << endl;
        }
        else
        {
            // cout << "0" << endl;
            // Subset Sum =
            ll subset = (sum) / 2;
            ll t1 = 0;
            for (int i = n; i >= 1; i--)
            {
                t1 = power(i, k);
                if (t1 > subset)
                {
                    continue;
                }
                else
                {
                    if (t1 == subset)
                    {
                        subset -= t1;
                        v[i] = 1;
                        break;
                    }
                    else
                    {
                        subset -= t1;
                        v[i] = 1;
                    }
                }
            }

            ll a = 0, b = 0;
            for (int i = 1; i <= n; i++)
            {
                if (v[i])
                {
                    b += power(i, k);
                }
                else
                {
                    a += power(i, k);
                }
            }

            cout << n << " -> " << abs(b - a) << endl;
            // cout << abs(b - a) << endl;

            for (int i = 1; i <= n; i++)
            {
                cout << v[i];
            }
            cout << endl;
        }
    }

    return 0;
}