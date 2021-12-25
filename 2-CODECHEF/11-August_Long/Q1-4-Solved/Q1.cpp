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
    ll k;

    w(t)
    {
        cin >> n >> k;

        ll p[n+1] ={ 0 };

        ll step;

        vector <pair<ll, ll>> v;
        ll gmin = 1e9 + 1;

        for (i=1;i<=n;i++)
        {
            cin >> p[i];
            if (p[i] < k)
            {
                step = 0;
                if (k%p[i]==0)
                {
                    step += (k - p[i])/p[i];
                    v.push_back(make_pair(p[i], step));
                    if (step < gmin)
                    {
                        gmin = step;
                    }
                }
            }
        }

        int sz = v.size();

        if (sz == 0)
        {
            cout << "-1" << endl;
            continue;
        }

        bool flag = true;
        for (i=0;i<sz;i++)
        {
            if (v[i].second == gmin)
            {
                cout << v[i].first << endl;
                flag = false;
                continue;
            }
        }

        if (flag)
        {
            cout << "-1" << endl;
        }


    }


    return 0;
}
