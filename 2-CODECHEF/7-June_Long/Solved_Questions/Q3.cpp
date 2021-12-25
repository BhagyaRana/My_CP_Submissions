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
typedef long long ll;
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

int main()
{
    b_v_r();
    w(t)
    {
        int n;
        cin >> n;
        mk(arr, n, int);
        int cnt5 = 0, cnt10 = 0;
        int i = 0;
        rep(i, n)
        {
            cin >> arr[i];
        }
        int gcount = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 5)
            {
                gcount++;
                cnt5++;
            }
            else
            {
                if (arr[i] == 10)
                {
                    cnt10++;
                    if (cnt5 > 0)
                    {
                        gcount++;
                        cnt5--;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    if (arr[i] == 15)
                    {
                        if (cnt10 > 0||(cnt5>1))
                        {
                            if(cnt10>0)
                            {
                                gcount++;
                                cnt10--;
                            }
                            else
                            {
                                gcount++;
                                cnt5 -= 2;
                            }
                            
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }
        if (gcount == n)
            cout << "YES" << endl;
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
