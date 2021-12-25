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
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

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
    int n, i, j;

    w(t)
    {
        cin >> n;

        ll a[n+1], b[n+1], amin = 1e9 + 1, bmin = 1e9 + 1;

        for (i=1;i<=n;i++)
        {
            cin >> a[i];
            if (a[i]<amin)
                amin = a[i];
        }
        for (i=1;i<=n;i++)
        {
            cin >> b[i];
            if (b[i]<bmin)
                bmin = b[i];
        }
        ll mvcnt = 0;
        ll d1, d2, temp;
        for (i=1;i<=n;i++)
        {
            while (a[i]!=amin || b[i]!=bmin)
            {

                d1 = a[i] - amin;
                d2 = b[i] - bmin;

                if (d1 >= 1 && d2 >=1)
                {
                    temp = min(d1, d2);
                    mvcnt += temp;
                    a[i] -= temp;
                    b[i] -= temp;
                }
                else
                {
                    if (d1 >= 1)
                    {
                        temp = a[i]-amin;
                        mvcnt += temp;
                        a[i] -= temp;
                    }
                    else
                    {
                        temp = b[i]-bmin;
                        mvcnt += temp;
                        b[i] -= temp;
                    }
                }
                if (a[i] == amin && b[i] == bmin)
                {
                    break;
                }
            }
        }

        cout << mvcnt << endl;

    }


    return 0;
}
