#include <bits/stdc++.h>

using namespace std;

#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define endl '\n'
#define long long ll
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

void prefixsum(int a[], int n)
{
    // cout<<"\nUPDATED :"<<endl;
    int max = -1;
    for (int i = 1; i < n; i++)
    {
        a[i] = a[i] + a[i - 1];
        if (a[i] > max)
            max = a[i];
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << a[i] << " ";
    // }

    cout << max << endl;
}

int main()
{
    b_v_r();
    int n, q;
    cin >> n;
    int arr[n + 2];
    arr[0] = 0;
    arr[n + 1] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        arr[i] = 0;
    }
    cin >> q;
    int l, r, k;
    while (q--)
    {
        cin >> l >> r >> k;
        arr[l] += k;
        arr[r + 1] -= k;
    }

    prefixsum(arr, n + 2);
    return 0;
}

