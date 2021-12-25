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
        int n;
        cin >> n;

        map<int, vector<int>> m;
        queue<int> q;

        int x;

        for (int i = 0; i < n; i++)
        {
            cin >> x;
            m[x].push_back(i);
        }

        for (int i = 0; i < n; i++)
        {
            cin >> x;
            q.push(x);
        }

        int cnt = 0, index = -1;

        if (!m[q.front()].empty())
        {
            index = m[q.front()][0];
            cnt++;
            q.pop();
        }
        else
        {
            cout << "-10099" << endl;
            goto end;
        }

        while (!q.empty())
        {
            if (!m[q.front()].empty())
            {
                for (int i = 0; i < m[q.front()].size(); i++)
                {
                    if (m[q.front()][i] > index)
                    {
                        index = m[q.front()][i];
                        q.pop();
                        goto skip;
                    }
                }
                index = m[q.front()][0];
                cnt++;
                q.pop();
            skip:;
            }
            else
            {
                cout << "-10099" << endl;
                goto end;
            }
        }

        cout << cnt << endl;

    end:;
    }

    return 0;
}
