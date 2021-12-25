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

vector<int> hashTable[1000001];

int main()
{
    b_v_r();
    int n, q;
    cin >> n >> q;
    mk(arr, n, int);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        hashTable[arr[i]].push_back(i + 1);
    }
    while (q--)
    {
        int d, k, l, r;
        cin >> d >> k >> l >> r;
        // Id -> d
        // kth Person
        // Range is Between l and r i inclusive
        // auto itr = hashTable[d].begin();
        // int count = 1;
        int flag = 0;
        // if (k <= hashTable[d].size())
        // {
        //     for (; itr != hashTable[d].end(); itr++)
        //     {
        //         flag = 1;
        //         if (count == k)
        //         {
        //             if (*itr >= l && *itr <= r)
        //             {
        //                 cout << (*itr) << endl;
        //             }
        //             else
        //             {
        //                 cout << "-1" << endl;
        //             }
        //         }
        //         count++;
        //     }
        // }
        // else
        // {
        //     cout << "-1" << endl;
        // }
        if (k <= hashTable[d].size())
        {
            int i = k - 1;

            if ((hashTable[d][i] >= l) && (hashTable[d][i] <= r))
            {
                cout << hashTable[d][i] << endl;
                flag = 1;
                // break;
            }
            else
            {
                flag = 1;
                // cout << hashTable[d][i] << endl;
                cout << "-1" << endl;
                // break;
            }
        }
        else
        {
            cout << "-1" << endl;
        }
        
    }

    return 0;
}
