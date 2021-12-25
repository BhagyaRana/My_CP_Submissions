#pragma GCC optimize("O2")

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

int findMaxGCD(int arr[], int n) 
{ 
    int high = 0; 
    for (int i = 0; i < n; i++) 
        high = max(high, arr[i]); 

    int divisors[high + 1] = { 0 }; 
    for (int i = 0; i < n; i++) 
    { 
        // Calculating all the divisors 
        for (int j = 1; j <= sqrt(arr[i]); j++) 
        { 
            if (arr[i] % j == 0) 
            { 
                divisors[j]++; 
                if (j != arr[i] / j) 
                    divisors[arr[i] / j]++; 
            } 
        } 
    } 
  
    for (int i = high; i >= 1; i--) 
    {
         if (divisors[i] > 1) 
            return i; 
    }

}

int main()
{
    b_v_r();
    w(t)
    {
        int n;

        int gmax = -1;

        cin >> n;
        mk(a, n, int);

        int ans = findMaxGCD(a,n);

        // mk(mark, n, int);

        // for(int i=0;i<n;i++)
        // {
        //     a[i] = i+1;
        //     mark[i] = 0;
        // }

        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 1; j * j <= a[i]; j++)
        //     {
        //         if (a[i] % j == 0)
        //         {
        //             mark[j]++;
        //             mark[a[i] / j]++;
        //         }
        //     }
        // }
        // for(int i=0;i<n;i++)
        // {
        //     if(mark[i]>2)
        //     {
        //         if(mark[i]>gmax)
        //             gmax = mark[i];
        //     }
        // }
        cout << ans << endl;
    }

    return 0;
}
