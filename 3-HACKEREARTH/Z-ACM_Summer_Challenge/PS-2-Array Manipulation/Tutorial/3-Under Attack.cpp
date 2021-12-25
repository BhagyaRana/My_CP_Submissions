#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define size 1000
#define endl '\n'
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

bool test1(int ar[size][size], int m, int n, int i, int j)
{
    for (int x = (i - 1); x < (i + 2); x++)
    {
        for (int y = (j - 1); y < (j + 2); y++)
        {
            if ((x >= 0 && x < m) and (y >= 0 && y < n))
            {

                if (ar[i][j] < ar[x][y])
                {
                    return true;
                }
            }
        }
    }
    return false;
}
int main()
{
    b_v_r();
    w(t)
    {
        int m, n;
        ll res = 0;
        cin >> m >> n;
        int ar[size][size];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> ar[i][j];
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (ar[i][j] != 0)
                {
                    bool check = test1(ar, m, n, i, j);
                    if (!check)
                    {
                        res = res + ar[i][j];
                    }
                }
            }
        }
        cout << res << endl;
    }
}