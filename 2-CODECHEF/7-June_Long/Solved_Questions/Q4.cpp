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
typedef unsigned long long int ull;
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

int fx(ull ts, ull js)
{
    if ((ts % 2 == 0) && (js % 2 == 0))
    {
        ts = ts / 2;
        js = js / 2;
        int a1 = fx(ts, js);
        return a1;
    }
    else
    {
        if ((ts % 2 != 0) && (js % 2 != 0))
        {
            return 1; //tie
        }
        else
        {
            if ((ts % 2 == 0) && (js % 2 != 0))
                return 2;
            else
            {
                return 3; // jerry win
            }
        }
    }
}

ull power(ull a, ull b)
{
    ull result = 1;
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
    int t;
    cin >> t;
    while (t--)
    {
        ull ts, cnt = 0ULL;
        cin >> ts;
        ull po2 = 0;
        ull temp = ts;
        while (!(temp % 2))
        {
            temp >>= 1; // equivalent to temp=temp/2;
            po2++;
        }
        if (ts % 2 != 0)
        {
            //ts is odd
            cnt += ((ts - 1) / 2);
            cout << cnt << endl;
        }
        else
        {
            // (n&(n-1)) -> zero //n is power of 2
            //power of 2 in i greater than power of 2 in ts
            if ((ts & (ts - 1)))
            {
                ull j = power(2, po2 + 1);
                ull k = 1;
                cnt += (ts / j);
                // while ((j * k) < ts)
                // {
                //     k++;
                //     cnt++;
                // }
                // for (ull i = j; i < ts; i += j)
                // {

                //     if (fx(ts, i) == 3)
                //     {
                //         cnt++;
                //     }
                // }
                cout << cnt << endl;
            }
            else
            {
                cout << cnt << endl;
            }
        }
        // cout << cnt << endl;
    }
    return 0;
}
