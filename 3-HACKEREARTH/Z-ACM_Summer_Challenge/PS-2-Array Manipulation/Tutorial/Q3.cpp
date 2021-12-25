#include <bits/stdc++.h>

using namespace std;

#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define endl '\n'
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

int findnear(int a[][1001], int i, int j, int m, int n)
{
    //a[i][j] ->
    // if(i-1) >= 0
    // if(i+1)  < m
    // if(j-1) >=0
    // if(j+1) < n
    bool c1 = false, c2 = false, c3 = false, c4 = false;
    if ((i - 1) >= 0) // row up
        c1 = true;
    if ((i + 1) < m) // row down
        c2 = true;
    if ((j - 1) >= 0) // col left
        c3 = true;
    if ((j + 1) < n) // col right
        c4 = true;
    int count = 0;
    if(c1&&c3)
    {
        if (a[i][j] > a[i - 1][j - 1])
            count++;
    }    
        
    if(c1)
    {
        if (a[i][j] > a[i - 1][j])
        count++;
    }        
    
    if(c1&&c4)
    {
        if (a[i][j] > a[i - 1][j + 1])
        count++;
    }
    
    if(c3)
    {
        if (a[i][j] > a[i][j - 1])
        count++;
    }
    
    if(c4)
    {
        if (a[i][j] > a[i][j + 1])
        count++;
    }
    
    if(c2&&c3)
    {
        if (a[i][j] > a[i + 1][j - 1])
        count++;
    }
    
    if(c2)
    {
        if (a[i][j] > a[i + 1][j])
        count++;
    }
    
    if(c2&&c4)
    {
        if (a[i][j] > a[i + 1][j + 1])
        count++;
    }
    
    return count;
}

int main()
{
    b_v_r();
    w(t)
    {
        int m, n;
        cin >> m >> n;
        int arr[1001][1001], near[1001][1001];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                near[i][j] = findnear(arr, i, j, m, n);
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << near[i][j] << " " ;
            }
            cout << endl;
        }


    }

    return 0;
}
