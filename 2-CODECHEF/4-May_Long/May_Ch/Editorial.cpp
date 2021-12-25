#include <bits/stdc++.h>
#define endl '\n'
#define SZ(x) ((int)x.size())

#define pb push_back

using namespace std;

int n;
string a;
string b;

void read()
{
    cin >> n;
    cin >> a;
    cin >> b;
}

void solve()
{
    //Check 1
    vector<vector<int>> ans; //2-d Matrix
    for (int i = 0; i < n; i++)
    {
        if (a[i] < b[i])
        {
            cout << -1 << endl;
            return;
        }
    }

    for (char c = 'z'; c >= 'a'; c--)
    {
        vector<int> pos;
        bool ok = 0;

        for (int i = 0; i < n; i++)
        {
            if (b[i] == c && a[i] != c)
            {
                pos.pb(i);
            }
        }

        if (!ok && !pos.empty())
        {
            for (int i = 0; i < n; i++)
            {
                if (a[i] == c)
                {
                    ok = 1;
                    pos.pb(i);
                }
            }
        }

        if (!ok && !pos.empty())
        {
            cout << -1 << endl;
            return;
        }

        if (!pos.empty())
            ans.pb(pos);
        for (int i : pos)
        {
            a[i] = c;
        }
    }

    cout << SZ(ans) << endl;
    for (auto li : ans)
    {
        cout << SZ(li) << " ";
        for (int x : li)
            cout << x << " ";
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        read();
        solve();
    }

    return 0;
}