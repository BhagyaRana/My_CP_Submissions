#include <bits/stdc++.h>

using namespace std;

#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define endl "\n"
typedef long long ll;
#define min(a, b) ((a > b) ? b : a)
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

    unsigned int n, m, q;
    cin >> n >> m >> q;

    mk(xcor, n, ll);
    mk(ycor, m, ll);

    int i, j, k;
    for (i = 0; i < n; i++)
        cin >> xcor[i];
    for (j = 0; j < m; j++)
        cin >> ycor[j];

    sort(xcor, xcor + n);

    sort(ycor, ycor + m);

    while (q--)
    {
        ll z;
        cin >> z;
        char c;
        cin >> c;
        if (c == 'A')
        {
            ll l1, r1;
            cin >> l1 >> r1;
            ll cnt = 0LL;
            // Now Start Logic

            // cout << "Query A" << endl;

            // x0 is between l1 and r1
            int indexx1 = lower_bound(xcor, xcor + n, l1) - xcor;
            // cout << "index x1 : " << indexx1 << endl;
            int indexx2 = upper_bound(xcor, xcor + n, r1) - xcor;
            // cout << "index x2 : " << indexx2 << endl;

            int end = m;

            for (i = indexx1; i < indexx2; i++)
            {
                while (xcor[i] + ycor[end - 1] > z && end > 0)
                    end--;
                cnt += end;
            }

            cout << cnt << endl;
        }
        else
        {
            if (c == 'B')
            {
                ll l2, r2;
                cin >> l2 >> r2;
                ll cnt = 0LL;
                //Now Start Logic

                // cout << "Query B" << endl;

                // y0 is between l2 and r2
                int indexy1 = lower_bound(ycor, ycor + m, l2) - ycor;
                // cout << "index y1 : " << indexy1 << endl;
                int indexy2 = upper_bound(ycor, ycor + m, r2) - ycor;
                // cout << "index y2 : " << indexy2 << endl;

                int end = n;

                for (i = indexy1; i < indexy2; i++)
                {
                    while (ycor[i] + xcor[end - 1] > z && end > 0)
                        end--;
                    cnt += end;
                }

                cout << cnt << endl;
            }
            else
            {
                if (c == 'C')
                {
                    ll l1, r1, l2, r2;
                    cin >> l1 >> r1 >> l2 >> r2;
                    ll cnt = 0LL;
                    // Now Start Logic

                    // cout << "Query C" << endl;

                    int indexx1 = lower_bound(xcor, xcor + n, l1) - xcor;
                    // cout << "index x1 : " << indexx1 << endl;
                    int indexx2 = upper_bound(xcor, xcor + n, r1) - xcor;
                    // cout << "index x2 : " << indexx2 << endl;
                    int indexy1 = lower_bound(ycor, ycor + m, l2) - ycor;
                    // cout << "index y1 : " << indexy1 << endl;
                    int indexy2 = upper_bound(ycor, ycor + m, r2) - ycor;
                    // cout << "index y2 : " << indexy2 << endl;

                    // x0 is between l1 and r1
                    // y0 is between l2 and r2

                    // int end1 = indexx2;
                    // int end2 = indexy2;

                    for (int i = indexx1; i < indexx2; i++)
                    {
                        while (xcor[i] + ycor[indexy2 - 1] > z && indexy2 > indexy1)
                        {
                            indexy2--;
                        }
                        cnt += (indexy2 - indexy1);
                    }

                    cout << cnt << endl;
                }
            }
        }
    }

    return 0;
}