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

struct Point
{
    int x, y;
};

int delicious(Point t)
{
}

int main()
{
    b_v_r();
    w(t)
    {
        int n, q;
        cin >> n >> q;
        Point points[n];
        for (int i = 0; i < n; i++)
        {
            cin >> points[i].x >> points[i].y;
        }
        Point query;
        while (q--)
        {
            cin >> query.x >> query.y;
            int ans = delicious(query);
            cout << ans << endl;
        }
    }
    return 0;
}
