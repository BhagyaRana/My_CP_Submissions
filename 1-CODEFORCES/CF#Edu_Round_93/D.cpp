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

    int R, G, B, i;

    cin >> R >> G >> B;

    vector<int> r(R);
    vector<int> g(G);
    vector<int> b(B);

    for (i = 0; i < R; i++)
        cin >> r[i];
    for (i = 0; i < G; i++)
        cin >> g[i];
    for (i = 0; i < B; i++)
        cin >> b[i];

    sort(r.begin(), r.end());
    sort(g.begin(), g.end());
    sort(b.begin(), b.end());

    stack<int> red;
    stack<int> gre;
    stack<int> blu;

    for (i = 0; i < R; i++)
        red.push(r[i]);
    for (i = 0; i < G; i++)
        gre.push(g[i]);
    for (i = 0; i < B; i++)
        blu.push(b[i]);

    ll ans = 0;
    ll tmp;
    ll rtop = 0, gtop = 0, btop = 0;
    ll rgp = 0, rbp = 0, gbp = 0;

    while ((!red.empty() && !gre.empty()) || (!red.empty() && !blu.empty()) || (!gre.empty() && !blu.empty()))
    {
        if (!red.empty())
            rtop = red.top();
        else
        {
            rtop = 0;
        }

        if (!gre.empty())
            gtop = gre.top();
        else
        {
            gtop = 0;
        }

        if (!blu.empty())
            btop = blu.top();
        else
        {
            btop = 0;
        }

        rgp = rtop * gtop;
        rbp = rtop * btop;
        gbp = gtop * btop;

        if (rgp >= rbp && rgp >= gbp)
        {
            ans += rgp;
            red.pop();
            gre.pop();
        }
        else
        {
            if (rbp >= rgp && rbp >= gbp)
            {
                ans += rbp;
                red.pop();
                blu.pop();
            }
            else
            {
                if (gbp >= rgp && gbp >= rbp)
                {
                    ans += gbp;
                    gre.pop();
                    blu.pop();
                }
                else
                {
                    ans += max(max(rgp,rbp),gbp);
                }
                
            }
        }
    }

    cout << ans << endl;

    return 0;
}
