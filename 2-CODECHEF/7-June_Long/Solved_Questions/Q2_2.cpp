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
        ll ans1 = 0,ans2 = 0;
        int n = s.length();
        // mk(vis, n, bool);
        for (int i = 0; i < n - 1; i++)
        {
            if(((s[i]=='x')&&(s[i+1]=='y'))||(((s[i]=='y')&&(s[i+1]=='x'))))
            {
                ans1++;
                i += 1;
            }
        }
        for (int i = 1; i < n - 1; i++)
        {
            if(((s[i]=='x')&&(s[i+1]=='y'))||(((s[i]=='y')&&(s[i+1]=='x'))))
            {
                ans2++;
                i += 1;
            }
        }

        cout << max(ans1,ans2) << endl;
    }

    return 0;
}
