// CodeForces #595 C1 Problem
#include <bits/stdc++.h>
using namespace std;

#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define endl "\n"
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define int long long
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

int n, ans, cnt;
vector<int> v;

void ConverttoBase3()
{
    while (n)
    {
        v.push_back(n % 3);
        n /= 3;
    }
    v.push_back(0);
}

int32_t main()
{
    w(t)
    {
        ans = 0;
        cnt = 1;
        v.clear();
        cin >> n;
        ConverttoBase3();
        for (int i = 0; i < v.size(); i++, cnt *= 3)
        {
            if (i == v.size() - 1)
                ans += v[i] * cnt;
            else if (v[i] >= 2)
            {
                v[i + 1]++;
                ans = 0;
            }
            else
                ans += v[i] * cnt;
        }
        cout << ans << endl;
    }

    return 0;
}