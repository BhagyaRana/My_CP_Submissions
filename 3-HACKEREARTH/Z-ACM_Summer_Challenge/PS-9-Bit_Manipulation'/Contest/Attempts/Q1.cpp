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
typedef unsigned long long ull;
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

int power_of_two(int n, int a[], int x)
{

    // To store the count of powers of two
    vector<int> cnt(31);

    for (int i = 0; i < n; ++i)
    {
        ++cnt[__builtin_ctz(a[i])];
    }

    int ans = 0;
    for (int i = 30; i >= 0 && x > 0; --i)
    {

        int need = min(x >> i, cnt[i]);
        ans += need;
        x -= (1 << i) * need;
    }

    if (x > 0)
        ans = -1;

    return ans;
}

int main()
{
    b_v_r();
    w(t)
    {
        int n;
        int m;
        cin >> n >> m;
        mk(arr, m, int);
        vector<int> v;
        int sum = 0;
        for (int i = 0; i < m; i++)
        {
            cin >> arr[i];
            sum += arr[i];
            v.push_back(arr[i]);
            while (arr[i] != 1)
            {
                arr[i] /= 2;
                v.push_back(arr[i]);
            }
        }
        int flag = 0;
        if (sum < n)
        {
            cout << "-1" << endl;
            flag = 1;
        }
        else
        {
            int len = v.size();
            // for(int i:v)
            // {
            //     cout << i << " ";
            // }
            // cout << endl;
            mk(arr1, len, int);

            for (int i = 0; i < len; i++)
            {
                arr1[i] = v[i];
            }

            int ans = power_of_two(len, arr1, n);

            cout << ans << endl;
        }
    }

    return 0;
}
