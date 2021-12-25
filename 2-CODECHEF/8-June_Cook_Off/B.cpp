#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define w(x)  \
    ll x;    \
    cin >> x; \
    while (x--)
#define endl "\n"
#define mk(arr, n, type) type *arr = new type[n]

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
        ll m, n;
        cin >> n >> m;

        ll arr[n+1];

        for (ll i = 1; i <= n ; i++)
        {
            cin >> arr[i];
        }

        set<ll> s;
        ll m_count = 0LL;
        int flag = 1;

        for (ll i = 1; i <= n; i++)
        {
            if (arr[i] == m)
            {
                m_count++;
            }
            else
            {
                if (arr[i] < m)
                    s.insert(arr[i]);
            }
        }

        if (s.size() != (m - 1))
        {
            flag = 0;
        }
        if(flag==0)
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << n - m_count << endl;
        }
    }
    return 0;
}
