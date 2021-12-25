#include <bits/stdc++.h>

using namespace std;


#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define endl "\n"
typedef long long ll;
const int MAX = 1000;

void spiralFill(int m, int n, int a[][MAX])
{

    int val = 1;
    int k = 0, l = 0;
    while (k < m && l < n)
    {

        for (int i = l; i < n; ++i)
            a[k][i] = val++;

        k++;

        for (int i = k; i < m; ++i)
            a[i][n - 1] = val++;
        n--;

        if (k < m)
        {
            for (int i = n - 1; i >= l; --i)
                a[m - 1][i] = val++;
            m--;
        }

        if (l < n)
        {
            for (int i = m - 1; i >= k; --i)
                a[i][l] = val++;
            l++;
        }
    }
}

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
        int a[MAX][MAX];
        spiralFill(n, n, a);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << a[i][j] << " ";
            cout << endl;
        }
    }

    return 0;
}
