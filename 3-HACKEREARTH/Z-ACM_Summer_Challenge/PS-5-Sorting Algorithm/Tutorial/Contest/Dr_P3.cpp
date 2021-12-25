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

// ll BinarySearchC(ll arr[], int st, int ed, ll ele)
// {
//     int start = st;
//     int end = ed;
//     int res = ed;
//     while (start <= end)
//     {
//         int mid = start + (end - start) / 2;
//         if (arr[mid] == ele)
//             return mid;
//         else
//         {
//             if (ele < arr[mid])
//             {
//                 // Ceil of Element
//                 res = mid;
//                 end = mid - 1;
//             }
//             else
//             { //arr[mid] < ele
//                 // Floor of Element
//                 // res = mid;
//                 start = mid + 1;
//             }
//         }
//     }
//     return res; //Not Found Case
// }

ll BinarySearchC(ll arr[], int low, int high, ll x)
{
    int mid;

    if (x <= arr[low])
        return low;

    if (x > arr[high])
        return high;

    mid = low + (high - low) / 2;

    if (arr[mid] == x)
        return mid;

    else if (arr[mid] < x)
    {
        if (mid + 1 <= high && x <= arr[mid + 1])
            return mid + 1;
        else
            return BinarySearchC(arr, mid + 1, high, x);
    }
    else
    {
        if (mid - 1 >= low && x > arr[mid - 1])
            return mid;
        else
            return BinarySearchC(arr, low, mid - 1, x);
    }
}

ll BinarySearchF(ll arr[], int low, int high, ll x)
{
    if (low > high)
        return -1;

    if (x >= arr[high])
        return high;

    int mid = (low + high) / 2;

    if (arr[mid] == x)
        return mid;

    if (mid > 0 && arr[mid - 1] <= x && x < arr[mid])
        return mid - 1;

    if (x < arr[mid])
        return BinarySearchF(arr, low, mid - 1, x);

    return BinarySearchF(arr, mid + 1, high, x);
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
            ll indexx1 = BinarySearchC(xcor, 0, n - 1, min(l1, z));
            // cout << "index x1 : " << indexx1 << endl;
            ll indexx2 = BinarySearchF(xcor, 0, n - 1, min(r1, z));
            // cout << "index x2 : " << indexx2 << endl;

            for (i = indexx1; i <= indexx2; i++)
            {

                if ((xcor[i] >= l1) && (xcor[i] <= r1) && (xcor[i] < z))
                {

                    ll end = m - 1;
                    while (end >= 0)
                    {
                        if (xcor[i] + ycor[end] <= z)
                        {
                            cnt += (end + 1);
                            break;
                        }
                        else
                        {
                            end--;
                        }
                    }
                }
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
                ll indexy1 = BinarySearchC(ycor, 0, m - 1, min(l2, z));
                // cout << "index y1 : " << indexy1 << endl;
                ll indexy2 = BinarySearchF(ycor, 0, m - 1, min(z, r2));
                // cout << "index y2 : " << indexy2 << endl;

                for (i = indexy1; i <= indexy2; i++)
                {

                    if ((ycor[i] >= l2) && (ycor[i] <= r2) && (ycor[i] < z))
                    {
                        ll end = n - 1;
                        while (end >= 0)
                        {
                            if (ycor[i] + xcor[end] <= z)
                            {
                                cnt += (end + 1);
                                break;
                            }
                            else
                            {
                                end--;
                            }
                        }
                    }
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

                    // x0 is between l1 and r1
                    // y0 is between l2 and r2
                    ll indexx1 = BinarySearchC(xcor, 0, n - 1, min(l1, z));
                    // cout << "index x1 : " << indexx1 << endl;
                    ll indexx2 = BinarySearchF(xcor, 0, n - 1, min(r1, z));
                    // cout << "index x2 : " << indexx2 << endl;

                    ll indexy1 = BinarySearchC(ycor, 0, m - 1, min(l2, z));
                    // cout << "index y1 : " << indexy1 << endl;
                    ll indexy2 = BinarySearchF(ycor, 0, m - 1, min(r2, z));
                    // cout << "index y2 : " << indexy2 << endl;

                    if (indexx2 - indexx1 == 0 || indexy2 - indexy1 == 0)
                    {
                        cout << cnt << endl;
                    }
                    else
                    {
                        for (i = indexx1; i <= indexx2; i++)
                        {
                            if ((xcor[i] >= l1) && (xcor[i] <= r1) && (xcor[i] < z))
                            {
                                //Check

                                ll end = indexy2;
                                while (end >= indexy1)
                                {
                                    if (xcor[i] + ycor[end] <= z)
                                    {
                                        cnt += ((end + 1) - indexy1);
                                        break;
                                    }
                                    else
                                    {
                                        end--;
                                    }
                                }
                            }
                        }

                        cout << cnt << endl;
                    }
                }
            }
        }
    }

    return 0;
}
