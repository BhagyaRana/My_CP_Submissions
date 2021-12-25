#include <bits/stdc++.h>

using namespace std;

const int MAX = 1001;

#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define endl "\n"
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define rep(i, n) for (i = 0; i < n; ++i)
#define REP(i, k, n) for (i = k; i <= n; ++i)
#define REPR(i, k, n) for (i = k; i >= n; --i)
typedef long long ll;
#define mk(arr, n, type) type *arr = new type[n]
const int mod = 1000000007;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

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

void spiralFill(int m, int n, int a[][MAX]) 
{ 
    
    int val = 1; 
    int k = 0, l = 0; 
    while (k < m && l < n) 
    { 
        
        for (int i = l; i < n; ++i) 
            a[k][i] = val++; 
  
        k++; 
  
  
        for (int i = k; i < m; ++i) 
            a[i][n-1] = val++; 
        n--; 
  
        if (k < m) 
        { 
            for (int i = n-1; i >= l; --i) 
                a[m-1][i] = val++; 
            m--; 
        } 
  
        if (l < n) 
        { 
            for (int i = m-1; i >= k; --i) 
                 a[i][l] = val++; 
            l++; 
        } 
    } 
} 

int main()
{
    b_v_r();
    w(t)
    {
        int n;
        cin >> n;
        // const int sz = n;
        // int b[sz][sz];
        int a[MAX][MAX];
        int s1 = n;
        spiralFill(n,n,a);

    
        // int L = 0, R = n - 1, T = 0, B = n - 1, dir = 0;
        // // dir 0,1,2,3
        // int num = 1;
        // while (L <= R && T <= B)
        // {
        //     if (dir == 0)
        //     {
        //         for (int k = L; k <= R; k++)
        //         {
        //             b[T][k] = num;
        //             num++;
        //             T++;
        //         }
        //     }
        //     else
        //     {
        //         if (dir == 1)
        //         {
        //             for (int k = T; k <= B; k++)
        //             {
        //                 b[k][R] = num;
        //                 num++;
        //                 R--;
        //             }
        //         }
        //         else
        //         {
        //             if (dir == 2)
        //             {
        //                 for (int k = R; k >= L; k--)
        //                 {
        //                     b[B][k] = num;
        //                     num++;
        //                     B--;
        //                 }
        //             }
        //             else
        //             {
        //                 if (dir == 3)
        //                 {
        //                     for (int k = B; k >= 0; k--)
        //                     {
        //                         b[k][L] = num;
        //                         num++;
        //                         L++;
        //                     }
        //                 }
        //             }
        //         }
        //     }
        //     dir = (dir + 1) % 4;
        // }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; i < n; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
