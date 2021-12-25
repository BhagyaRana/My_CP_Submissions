#include <bits/stdc++.h>

using namespace std;

#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define endl "\n"
#define rep(i, n) for (i = 0; i < n; ++i)
typedef unsigned long long int ull;
typedef long long int ll;
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
    ull n;
    cin >> n;
    mk(arr, n, ull);
    mk(wait, n, ull);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // int k = sizeof(arr)/sizeof(arr[0]);
    sort(arr, arr + n);
    // sort(arr, arr+n);
    // mergeSort(arr, 0, k - 1);
    // cout << "ARRAY : "<<endl;
    // for(int i=0;i<n;i++)
    // {
    //     cout << arr[i] << " ";
    // }
    wait[0] = 0ULL;
    // ull cnt = 1;
    ull d = 0ULL;
    for (int i = 1; i < n; i++)
    {
        wait[i] = wait[i - 1] + arr[i - 1];
        if (wait[i] > arr[i])
            d++;
    }
    cout << n-d << endl;
    // cout << "WAIT : "<<endl;
    // for(int i=0;i<n;i++)
    // {
    //     cout << wait[i] << " ";
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     if (wait[i] <= arr[i])
    //         cnt++;
    // }
    // cout << cnt << endl;

    return 0;
}
