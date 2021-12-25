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

    int n, m, l, i, temp;
    string virus, s;
    
    int cvcnt = 0, gvcnt = 0;

    cin >> n;

    cin >> m;
    cin >> virus;

    int g[n] = {0}, c[n] = {0};
    
    for (i = 0; i < m; i++)
    {
        if (virus[i] == 'C')
        {
            cvcnt++;
        }
        else
        {
            if (virus[i] == 'G')
            {
                gvcnt++;
            }
        }
    }

    int mxn = -1;

    for (i = 0; i < n; i++)
    {
        cin >> l;
        cin >> s;
        for (int j = 0; j < l; j++)
        {
            if (s[j] == 'C')
            {
                c[i]++;
            }
            else
            {
                if (s[j] == 'G')
                {
                    g[i]++;
                }
            }
        }
        temp = ((g[i] * cvcnt) + (c[i] * gvcnt));
        if (temp > mxn)
        {
            mxn = temp;
        }
    }

    int min1 = 1001;

    for (i = 0; i < n; i++)
    {
        temp = (g[i] * cvcnt) + (c[i] * gvcnt);
        if (temp == mxn)
        {
            min1 = min(min1, i+1);
        }
    }

    cout << min1 << endl;

    return 0;
}
