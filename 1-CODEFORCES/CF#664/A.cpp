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

auto random_address = [] { char *p = new char; delete p; return (uint64_t) p; };
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1));

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
    ll a[4];
    w(t)
    {
        ll even = 0;
        ll min = 1e9 + 1;
        for (int i = 0; i < 4; i++)
        {
            cin >> a[i];
            if (a[i] % 2 == 0)
                even++;
            if (a[i] < min)
            {
                min = a[i];
            }
        }

        bool cdn = ((a[0] == 0 || a[1] == 0 || a[2] == 0)) ? true : false;

        if (even >= 3)
        {
            cout << "Yes" << endl;
            continue;
        }

        if (cdn)
        {
            cout << "No" << endl;
            continue;
        }

        bool flag = true;
        ll opcnt = 0;
        while ((a[0] != 0) && (a[1] != 0) && (a[2] != 0))
        {
            a[0]--;
            a[1]--;
            a[2]--;
            a[3] += 3;
            opcnt++;
            int ev1 = 0;
            for (int i = 0; i < 4; i++)
            {
                if (a[i] % 2 == 0)
                    ev1++;
            }
            if (ev1 >= 3)
            {
                cout << "Yes" << endl;
                flag = false;
                break;
            }

            if (opcnt > 16)
            {
                break;
            }
        }

        int ev3 = 0;

        for (int i = 0; i < 4; i++)
        {

            if (a[i] % 2 == 0)
                ev3++;
        }

        if (ev3 >= 3 && flag)
        {
            cout << "Yes" << endl;
            continue;
        }

        if (flag)
        {
            cout << "No" << endl;
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed\t: " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
#endif

    return 0;
}
