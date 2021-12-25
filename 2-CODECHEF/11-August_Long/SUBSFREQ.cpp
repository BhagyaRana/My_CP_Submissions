#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

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

    ll n, i;

    w(t)
    {
        cin >> n;

        ll a[n];

        vector<ll> v;

        for (i=0; i<n;i++)
        {
            cin >> a[i];
        }

        ll sbst = pow(2, n);
        ll freq[n+1] ={ 0 };


        for (ll cntr = 1; cntr < sbst; cntr++)
        {
            unordered_map<ll, ll> mp;
            for (ll j = 0LL; j < n; j++)
            {
                if (cntr & (1<<j))
                {
                    if (mp.find(a[j]) == mp.end())
                    {
                        mp.insert(make_pair(a[j], 1));
                    }
                    else
                    {
                        mp[a[j]]++;
                    }
                    // cout << a[j] << " ";
                }
            }

            ll mxn = 0LL;

            for (auto ele : mp)
            {
                if (ele.second > mxn)
                    mxn = ele.second;
            }

            for (auto ele : mp)
            {
                if (ele.second == mxn)
                {
                    freq[ele.first] = (freq[ele.first] + 1)%mod;
                    break;
                }
            }
            // cout << endl;
        }


        for (ll i=1;i<=n;i++)
        {
            cout << (freq[i]) << " ";
        }

        cout << endl;

    }

    return 0;
}
