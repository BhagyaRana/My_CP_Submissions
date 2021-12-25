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
        vector<ll> a(n);
        // ll a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());

        if (n == 1)
        {
            cout << "first" << endl;
            continue;
        }

        if (n == 2)
        {
            if (a[1] > a[0])
            {
                cout << "second" << endl;
                continue;
            }
            else
            {
                if (a[0] > a[1])
                {
                    cout << "first" << endl;
                    continue;
                }
                else
                {
                    cout << "draw" << endl;
                    continue;
                }
            }
        }

        ll ap1 = a[0], ap2 = a[1];

        for (int i = 2; i < n; i++)
        {
            if (i % 2 == 0)
            {
                ap2 += a[i];
            }
            else
            {
                ap1 += a[i];
            }
        }

        if (ap1 < ap2)
        {
            cout << "second" << endl;
            continue;
        }

        ll ap3 = 0, ap4 = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                ap3 += a[i];
            }
            else
            {
                ap4 += a[i];
            }
        }

        if (ap1 > ap2 && ap3 > ap4)
        {
            cout << "first" << endl;
            continue;
        }

        if (ap1 > ap2 && ap3 < ap4)
        {
            cout << "second" << endl;
            continue;
        }

        if (ap1 > ap2 && ap3 == ap4)
        {
            cout << "draw" << endl;
            continue;
        }

        if (ap2 == ap1 && ap3 > ap4)
        {
            cout << "draw" << endl;
            continue;
        }

        if (ap2 == ap1 && ap3 == ap4)
        {
            cout << "draw" << endl;
            continue;
        }

        if (ap2 == ap1 && ap3 < ap4)
        {
            cout << "second" << endl;
            continue;
        }
    }

    return 0;
}
