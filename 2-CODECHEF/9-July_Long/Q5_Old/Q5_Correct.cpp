#pragma GCC optimize("O2")

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

#define w(x)  \
    ll x;     \
    cin >> x; \
    while (x--)
#define endl "\n"
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)

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

    ll n;

    w(t)
    {
        cin >> n;

        ll a[n], b[n];

        ll min1 = 1000000001, min2 = 1000000001;

        unordered_map<ll, ll> freqA;
        unordered_map<ll, ll> freqB;

        vector<ll> v;

        set<ll> ele;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];

            if (a[i] < min1)
            {
                min1 = a[i];
            }

            if (freqA.find(a[i]) == freqA.end())
            {
                freqA[a[i]] = 1;
            }
            else
            {
                freqA[a[i]]++;
            }

            if (freqB.find(a[i]) == freqB.end())
            {
                freqB[a[i]] = 0;
            }

            ele.insert(a[i]);
        }

        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            if (b[i] < min2)
            {
                min2 = b[i];
            }

            if (freqB.find(b[i]) == freqB.end())
            {
                freqB[b[i]] = 1;
            }
            else
            {
                freqB[b[i]]++;
            }

            if (freqA.find(b[i]) == freqA.end())
            {
                freqA[b[i]] = 0;
            }

            ele.insert(b[i]);
        }

        // for (auto itr = freqA.begin(); itr != freqA.end(); ++itr)
        // {
        // cout << '\t' << itr->first
        //      << '\t' << itr->second << '\n';
        // }
        // cout << endl;

        // for (auto itr = freqB.begin(); itr != freqB.end(); ++itr)
        // {
        // cout << '\t' << itr->first
        //      << '\t' << itr->second << '\n';
        // }
        // cout << endl;

        ll cost = 0LL;
        bool flag = true;

        auto it2 = ele.begin();
        ll min_num = *it2;

        for (auto it = ele.begin(); it != ele.end(); it++)
        {
            if ((freqA[*it] + freqB[*it]) % 2 != 0)
            {
                // cout << "*it = " << *it << endl;
                flag = false;
                cout << "-1" << endl;
                break;
            }
            else
            {
                if (freqA[*it] != freqB[*it])
                {
                    ll v1 = freqA[*it];
                    ll v2 = freqB[*it];
                    ll cnt = 0LL;
                    if (v1 - v2 >= 0)
                    {
                        cnt = v1 - v2;
                    }
                    else
                    {
                        cnt = v2 - v1;
                    }

                    for (ll i = 0; i < cnt / 2; i++)
                    {
                        v.push_back(*it);
                    }
                }
            }
        }

        if (flag)
        {
            ll szz = v.size();
            sort(v.begin(), v.end());
            for (ll i = 0; i < ((szz) / 2); i++)
            {
                if (v[i] <= (min1 * 2) && v[i] <= (min2 * 2))
                    cost += v[i];
                else
                {
                    cost += min(min1 * 2, min2 * 2);
                }
            }
            cout << cost << endl;
        }
    }

    return 0;
}
