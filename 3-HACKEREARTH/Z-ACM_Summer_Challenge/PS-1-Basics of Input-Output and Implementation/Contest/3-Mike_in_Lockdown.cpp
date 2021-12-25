#include <bits/stdc++.h>
using namespace std;
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
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int k = 0, count = 0;
        mk(a, n, int);
        mk(b, n, int);
        mk(c, n, int);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> c[i];
            k = a[i] + b[i] - c[i];
            if (k > 0)
                count += k;
        }
        cout << count << "\n";
    }

    return 0;
}