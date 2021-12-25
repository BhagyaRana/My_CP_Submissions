#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
typedef unsigned int ll;
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

vector<int> hashTable[1000003];

int main()
{
    b_v_r();
    int n, q;
    cin >> n >> q;
    mk(arr, n, int);
    memset(hashTable, 0, sizeof(hashTable));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        hashTable[arr[i]].push_back(i + 1);
    }

    while (q--)
    {
        int d, k, l, r;

        cin >> d >> k >> l >> r;

        bool flag = true;

        if ((k <= hashTable[d].size()) && (hashTable[d][0] != 0))
        {
            if ((hashTable[d][k - 1] >= l) && (hashTable[d][k - 1] <= r))
            {
                cout << hashTable[d][k - 1] << endl;
                flag = false;
            }
            else
            {
                flag = false;
                cout << "-1" << endl;
            }
        }

        if (flag)
            cout << "-1" << endl;
    }

    return 0;
}
