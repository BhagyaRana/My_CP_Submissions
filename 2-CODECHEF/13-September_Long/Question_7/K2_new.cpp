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
// string str2[1000002];
string str[5] = {"", "0", "10", "110", "0110"};

string str2[14] = {"", "1", "10", "110", "1110", "10110", "110110", "1101001", "01101001", "101101001", "1000111010", "01000111010", "000000001101", "0110100010101"};

string str2_8 = "10010110";

vector<string> s2;

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

int main()
{
    b_v_r();
    int k;
    cin >> k;
    int n; // 10^6
    int t;
    cin >> t;
    if (k == 1)
    {
        while (t--)
        {
            int n;
            cin >> n;
            if (n == 1)
            {
                cout << 1 << endl;
                cout << 1 << endl;
                continue;
            }

            int res;
            if (n % 4 == 0 || n % 3 == 0)
            {
                res = 0;
            }
            else
            {
                res = 1;
            }
            // cout << res << endl;
            // cout << n << " -> " << res << endl;

            string ans = "";
            for (int i = 0; i < n / 4; i++)
            {
                ans += str[4];
            }
            int temp;
            if (n % 4 == 1)
            {
                ans = str[1] + ans;
            }
            else if (n % 4 == 2)
            {
                ans = str[2] + ans;
            }
            else if (n % 4 == 3)
            {
                ans = str[3] + ans;
            }

            ll a = 0, b = 0;
            for (int i = 1; i <= n; i++)
            {
                if (ans[i - 1] == (char)'1')
                {
                    b += i;
                }
                else
                {
                    a += i;
                }
            }

            // cout << n << " -> " << abs(b - a) << endl;
            cout << abs(b - a) << endl;

            cout << ans << endl;
        }
    }
    else if (k == 2)
    {
        while (t--)
        {
            int n;
            cin >> n;
            if (n > 8)
            {
                int sum = 1;
                sum *= n;
                sum *= (n + 1);
                sum /= 2;
                sum *= ((2 * n) + 1);
                sum /= 3;
                if (sum & 1)
                {
                    cout << 1 << endl;
                }
                else
                {
                    cout << 0 << endl;
                }
            }
            else
            {
                string ans = str2[n];
                ll a = 0, b = 0;
                for (int i = 0; i < n; i++)
                {
                    if (ans[i] == '1')
                    {
                        a += ((i + 1) * (i + 1));
                    }
                    else
                    {
                        b += ((i + 1) * (i + 1));
                    }
                }
                cout << abs(b - a) << endl;
            }
            if (n <= 13)
                cout << str2[n] << endl;
            else
            {
                string ans = "";
                int len = n;
                string t1 = "";
                // int cnt = 1;

                int r = len % 8;
                int cnt = len / 8;

                if (r < 6)
                {
                    cnt--;
                }

                for (int p = 0; p < cnt; p++)
                {
                    t1 = t1 + str2_8;
                }

                int st = n - (cnt * 8);

                string final = "";

                final += str2[st];

                final = final + t1;
                // ans = str2[rem] + ans;
                cout << final << endl;
            }
        }
    }
    else if (k == 3)
    {
        while (t--)
        {
            int n;
            cin >> n;
            cout << 1 << endl;
            cout << 1 << endl;
        }
    }
    else if (k == 4)
    {
        while (t--)
        {
            int n;
            cin >> n;
            cout << 1 << endl;
            cout << 1 << endl;
        }
    }

    return 0;
}