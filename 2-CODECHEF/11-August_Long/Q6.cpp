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
typedef long long int ll;
const int mod = 1000000007;

#define watch(x) cout << (#x) << " is : " << (x) << "\n"

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

    ll n, i;

    w(t)
    {
        cin >> n;
        ll a[n];

        for (i=0; i<n;i++)
        {
            cin >> a[i];
        }

        ll freq[n];
        ll prod = 1;

        for (i=n-1;i>=0;i--)
        {
            freq[i] = prod;
            prod = (prod*2)%mod;
        }


        for (i=0; i<n;i++)
        {
            cout << freq[i] << " ";
        }
        cout << endl;

    }

    return 0;
}
