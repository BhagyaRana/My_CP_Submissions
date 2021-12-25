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

// All Functions Here

// All Variables Here

int main()
{
    b_v_r();
    int n;
    w(t)
    {
        cin >> n;

        vector<ll> v(n);

        for (int i = 0; i < n; i++)
            cin >> v[i];

        for (int i = 0; i < n; i++)
        {
            if (i & 1)
            {
                if (v[i] < 0)
                {
                    v[i] *= (-1);
                }
            }
            else
            {
                if (v[i] > 0)
                {
                    v[i] *= (-1);
                }
            }
        }
        for (auto ele : v)
        {
            cout << ele << " ";
        }
        cout << endl;
    }

    return 0;
}