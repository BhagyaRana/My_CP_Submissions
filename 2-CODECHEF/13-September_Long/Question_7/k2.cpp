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

string str3[29] = {"", "1", "10", "110", "1110", "11110", "011110", "0001110", "00110110", "011010110", "1111111010", "00001101001", "001011100110", "0011110101001", "01011001101001", "001111010111100", "0110100110010110", "10010110111110010", "010011010101011010", "1100110110100111100", "01011111110111111000", "001010011111111010010", "0001000111111101111000", "10001111101111110111000", "111110111111011101001001", "0011111111011101111010100", "01111111001101111111101000", "011101101111111011111110000", "1011111111111001011111011000"};

string str2_8 = "10010110";
string str3_16 = "0110100110010110";
string str4_32 = "";

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

    if (k == 1)
    {
        int t;
        cin >> t;
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
        int t;
        cin >> t;
        int val[14] = {0, 1, 3, 4, 2, 3, 1, 0, 0, 1, 1, 0, 0, 1};
        while (t--)
        {
            int n;
            cin >> n;
            if (n <= 13)
            {
                cout << val[n] << endl;
                cout << str2[n] << endl;
            }
            else
            {
                int len = n;
                int cnt = 0;
                while (len > 13)
                {
                    cnt++;
                    len -= 8;
                }
                if (n % 4 == 1 || n % 4 == 2)
                {
                    cout << "1" << endl;
                }
                else
                {
                    cout << "0" << endl;
                }
                cout << str2[len];
                for (int i = 0; i < cnt; i++)
                {
                    cout << str2_8;
                }
                cout << endl;
            }
        }
    }
    else if (k == 3)
    {

        int val[29] = {0, 1, 7, 18, 28, 25, 7, 26, 4, 5, 1, 12, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0};
        int t;
        cin >> t;
        while (t--)
        {
            int n;
            cin >> n;
            if (n <= 28)
            {
                cout << val[n] << endl;
                cout << str3[n] << endl;
            }
            else
            {
                int len = n;
                int cnt = 0;
                while (len > 28)
                {
                    cnt++;
                    len -= 16;
                }
                if (n % 4 == 1 || n % 4 == 2)
                {
                    cout << "1" << endl;
                }
                else
                {
                    cout << "0" << endl;
                }
                cout << str3[len];
                for (int i = 0; i < cnt; i++)
                {
                    cout << str3_16;
                }
                cout << endl;
            }
        }
    }
    else if (k == 4)
    {
        int t;
        cin >> t;
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