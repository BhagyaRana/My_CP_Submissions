#include <bits/stdc++.h>

using namespace std;

#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define endl "\n"
typedef long long ll;
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

    int n, m, k;
    cin >> n >> m >> k;

    ll arr[n + 1][m + 1];

    memset(arr, 0, sizeof(arr[0][0]) * (n + 1) * (m + 1));

    short int qn;

    ll rank = 1;

    map <int, int> mpr;
    map <int, int> mpc;

    while (k--)
    {
        cin >> qn;
        if (qn == 1)
        {
            int r1;
            ll a1;
            cin >> r1 >> a1;
            arr[r1][0] = a1;
            if (mpr.find(r1) == mpr.end())
                mpr.insert(pair<int, int>(r1, rank));
            else
            {
                mpr[r1] = rank;
            }
            rank++;
        }
        else
        {
            if (qn == 2)
            {
                int c1;
                ll a1;
                cin >> c1 >> a1;
                arr[0][c1] = a1;
                if (mpc.find(c1) == mpc.end())
                    mpc.insert(pair<int, int>(c1, rank));
                else
                {
                    mpc[c1] = rank;
                }
                rank++;
            }
        }
    }

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (arr[i][0] == 0 && arr[0][j] != 0)
            {
                arr[i][j] = arr[0][j];
            }
            else
            {
                if (arr[0][j] == 0 && arr[i][0] != 0)
                {
                    arr[i][j] = arr[i][0];
                }
                else
                {
                    if (arr[0][j] != 0 && arr[i][0] != 0)
                    {
                        // which value came last will be value
                        // mpr[i] > mpc[j]
                        if (mpr.at(i) > mpc.at(j))
                        {
                            arr[i][j] = arr[i][0];
                        }
                        else
                        {
                            arr[i][j] = arr[0][j];
                        }
                    }
                }
            }
            // cout << arr[i][j] << " ";
        }
        // cout << endl;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
