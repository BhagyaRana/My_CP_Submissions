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
        string s;
        cin >> s;
        unsigned int ans = 0;
        int n = s.length();
        mk(vis, n, bool);
        for (int i = 0; i < n; i++)
        {
            if ((s[i] == 'x') && (vis[i] == false))
            {

                if ((i + 1 < n) && (s[i + 1] == 'y') && (vis[i + 1] == false))
                {
                    ans++;
                    vis[i] = true;
                    vis[i + 1] = true;
                    i ++;
                }
                else
                {
                    if ((i - 1 >= 0) && (s[i - 1] == 'y') && (vis[i - 1] == false))
                    {
                        ans++;
                        vis[i] = true;
                        vis[i - 1] = true;
                    }
                }
            }
            else
            {
                if (s[i] == 'y' && vis[i] == false)
                {
                    if ((i + 1 < n) && (s[i + 1] == 'x') && (vis[i + 1] == false))
                    {
                        ans++;
                        vis[i] = true;
                        vis[i + 1] = true;
                        i++;
                    }
                }
                else
                {

                    if ((i - 1 >= 0) && (s[i - 1] == 'x') && (vis[i - 1] == false))
                    {
                        ans++;
                        vis[i] = true;
                        vis[i - 1] = true;
                    }
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}