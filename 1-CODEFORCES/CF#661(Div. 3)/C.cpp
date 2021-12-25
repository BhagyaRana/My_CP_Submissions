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

        int w[n] ={ 0 };

        for (i=0;i<n;i++)
        {
            cin >> w[i];
        }

        if (n==1)
        {
            cout << "0" << endl;
            continue;
        }

        if (n==2 || n==3)
        {
            cout << "1" << endl;
            continue;
        }

        sort(w, w+n);

        int fin = 0;

        for (i=0;i<n;i++)
        {
            for (j=i+1;j<n;j++)
            {
                int s = w[i] + w[j];
                int cnt  = 0;
                int x = i, y = j;
                while (x<y)
                {
                    if (w[x]+w[y] > s)
                    {
                        y--;
                    }
                    else
                    {
                        if (w[x] + w[y] < s)
                        {
                            x++;
                        }
                        else
                        {
                            if (w[x] + w[y] == s)
                            {
                                cnt++;
                                x++;
                                y--;
                            }
                        }

                    }

                }

                fin = max(fin, cnt);
            }
        }

        cout << fin << endl;

    }

    return 0;
}
