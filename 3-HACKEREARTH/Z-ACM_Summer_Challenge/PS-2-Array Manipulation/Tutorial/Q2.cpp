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

 
int nCrModpDP(int n, int r, int p) 
{ 
   
    int C[r+1]; 
    memset(C, 0, sizeof(C)); 
    C[0] = 1; // Top row of Pascal Triangle 
    for (int i = 1; i <= n; i++) 
    { 
        
        for (int j = min(i, r); j > 0; j--) 
            C[j] = (C[j] + C[j-1])%p; 
    } 
    return C[r]; 
} 
  

int nCrModpLucas(int n, int r, int p) 
{ 
   if (r==0) 
      return 1; 
   int ni = n%p, ri = r%p; 
   return (nCrModpLucas(n/p, r/p, p) * // Last digits of n and r 
           nCrModpDP(ni, ri, p)) % p;  // Remaining digits 
} 

int main()
{
    b_v_r();
    int n;
    int k,mod = 1000000007;
    cin >> n >> k;
    if(k<5)
    {
        mk(arr, (k*n), int);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int sub = 0;
        for (int i = 0; i < (k*n); i++)
        {
            for(int j = i + 1 ; j < n ; j++)
            {
                if(arr[i]>arr[j])
                {
                    sub++;
                }
        }
    }
    if(k==1)
        cout<<sub<<endl;

    }
    else
    {
        mk(arr, (k*n), int);

    }
    
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int sub = 0;
    for (int i = 0; i < n; i++)
    {
        for(int j = i + 1 ; j < n ; j++)
        {
            if(arr[i]>arr[j])
            {
                sub++;
            }
        }
    }
    if(k==1)
        cout<<sub<<endl;
    else
    {
        int ans = 1;
        ans = (ans*sub) % mod;

        ans = (ans*(nCrModpLucas(k+1,2,mod))) % mod;
     
        cout << ans << endl;    
    }
        
    return 0;
}
