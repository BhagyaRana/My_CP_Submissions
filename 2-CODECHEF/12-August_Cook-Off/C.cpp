#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

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

// All Functions Here

// All Variables Here

int main()
{
    b_v_r();
    w(t)
    {
        int k, n;

        cin >> n >> k;

        int part = n / k;

        string s;

        cin >> s;

        int len = s.length();

        int cnt1 = 0, cnt0 = 0;

        for (int i = 0; i < len; i++)
        {
            if (s[i] == '1')
            {
                cnt1++;
            }
            else
            {
                cnt0++;
            }
        }

        int n1 = cnt0 / part;
        int n2 = cnt1 / part;

        int r1 = cnt0 % part;
        int r2 = cnt1 % part;
        // watch2(r1,r2);
        if (r1 != r2)
        {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        if (k == 1)
        {
            if (cnt0 == 0 || cnt1 == 0)
            {
                cout << s << endl;
                continue;
            }
            else
            {
                cout << "IMPOSSIBLE" << endl;
                continue;
            }
        }

        if ((n1 + n2) != k)
        {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        string tmp;
        for (int i = 1; i <= n1; i++)
        {
            tmp += '0';
        }
        for (int i = 1; i <= n2; i++)
        {
            tmp += '1';
        }

        sort(tmp.begin(), tmp.end());
        string rtmp = tmp;
        reverse(rtmp.begin(), rtmp.end());
        string ans;
        for (int i = 0; i < part; i++)
        {
            if (i % 2 == 0)
            {
                ans += tmp;
            }
            else
            {
                ans += rtmp;
            }
        }
        cout << ans << endl;
    }

    return 0;
}