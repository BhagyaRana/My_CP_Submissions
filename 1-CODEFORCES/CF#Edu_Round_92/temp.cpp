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
    int n, i;
    w(t)
    {
        cin >> n;
        int p[n + 1] = {0}, c[n + 1] = {0};
        for (i = 1; i <= n; i++)
        {
            cin >> p[i] >> c[i];
        }

        // Check 3 Conditions
        bool flag = true;
        for (i = 1; i <= n; i++)
        {
            // Plays of Current must be Greater than/Equal Plays of its Ancestor 
            if (!(p[i] >= p[i - 1]))
            {
                flag = false;
                break;
            }

            // Clears of Current must be Greater than/Equal Clears of its Ancestor 
            if (!(c[i] >= c[i - 1]))
            {
                flag = false;
                break;
            }

            // Difference of Plays should Always be Greater than Difference of Clears
            if (!((p[i] - p[i - 1]) >= (c[i] - c[i - 1])))
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
