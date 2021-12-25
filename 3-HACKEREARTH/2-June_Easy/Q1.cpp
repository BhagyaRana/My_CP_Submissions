#include <bits/stdc++.h>

using namespace std;

#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define endl "\n"
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define rep(i, n) for (i = 0; i < n; ++i)
#define REP(i, k, n) for (i = k; i <= n; ++i)
#define REPR(i, k, n) for (i = k; i >= n; --i)
typedef unsigned long long ull;
#define mk(arr, n, type) type *arr = new type[n]
const int mod = 1000000007;

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
        ull l, r;
        cin >> l >> r;
        ull cnt = 0ULL;
        ull num1 = 0ULL, num2 = 0ULL;
        ull total = r - l + 1;
        for (int i = 0; i < 4; i++)
        {
            if ((l + i) % 4 == 2 && (l + i <= r))
                num1 = (l + i);
            if ((r - i) % 4 == 2 && (r - i >= l))
                num2 = (r - i);
        }
        // cout << "num1 :" << num1 << endl;
        // cout << "num2 :" << num2 << endl;
        if (num1==0 || num2==0)
        {
            cout << (total - cnt) << endl;
        }
        else
        {
            cnt = ((ull)((num2 - num1) / (ull)4)) + (ull)1;
            cout << (total - cnt) << endl;
        }
    }

    return 0;
}
