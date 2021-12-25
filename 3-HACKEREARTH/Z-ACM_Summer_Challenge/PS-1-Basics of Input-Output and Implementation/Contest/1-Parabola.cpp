#include <bits/stdc++.h>
using namespace std;

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
    int t;
    float x, y, a;
    cin >> t;
    while (t--)
    {
        cin >> x >> y >> a;
        if (((x * x) - (4 * a * y)) == 0)
            cout << "YES"
                 << "\n";
        else
        {
            cout << "NO"
                 << "\n";
        }
    }

    return 0;
}