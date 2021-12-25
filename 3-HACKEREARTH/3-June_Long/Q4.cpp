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

ll sum(ll arr[], ll n, ll num)
{
    ll sum = 0LL;
    for (ll i = 0; i < n; i++)
    {
        sum += (arr[i] & num);
    }
    return sum;
}

ll power(ll a,ll b)
{
    ll result = 1;
    while(b)
    {
        if(b%2) result *= a;
        a *= a;
        b /= 2;
    }
    return result;
}


int main()
{
    b_v_r();
    w(t)
    {
        int n, l;
        cin >> n >> l;
        mk(arr, n, ll);

        bitset<32> bits;
        bitset<32> finalans;

        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            bits |= arr[i];
        }

        if (l > bits.count())
        {
            cout << "-1" << endl;
            continue;
        }

        cout << "FINAL : " << bits << endl;

        vector<int> oneindex;
        for (int i = 0; i < 32; i++)
        {
            if (bits[i] == 1)
            {
                oneindex.push_back(i);
            }
        }
        int sz = oneindex.size();
        int l_temp = l;
        for (int i = sz - 1; i >= 0; i--)
        {
            if (l_temp > 0)
            {
                finalans[i] = 1;
                l_temp--;
            }
            else
            {
                break;
            }
        }
        cout << "Final Ans : "<<finalans << endl;
        int count_zero = 0;
        for(int i = sz-1;i >= 0;i--)
        {
            if(finalans[i]==0)
                count_zero++;
        }
        ll ans1 = power(2,count_zero);
        cout << ans1 << endl;


        // sort(arr,arr+n);
        // int max = arr[n-1];
        // map<ll,ll> mp;
        // ll gmax = -1;
        // for(ll i=1;i<=max;i++)
        // {
        //     bitset<32> b1(i);
        //     if(b1.count()==l)
        //     {
        //         ll ssum = sum(arr, n, i);
        //         mp[ssum] += 1;
        //         if(ssum>gmax)
        //             gmax = ssum;
        //     }
        // }
        // cout << mp[gmax] << endl;
    }

    return 0;
}
