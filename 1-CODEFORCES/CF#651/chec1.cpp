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

ll binomialCoeff(ll n, ll k) 
{ 
    int C[k+1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1;  // nC0 is 1 
  
    for (ll i = 1; i <= n; i++) 
    { 
        for (ll j = min(i, k); j > 0; j--) 
            C[j] = C[j] + C[j-1]; 
    } 
    return C[k]; 
} 

int main()
{
    b_v_r();
    w(t)
    {
        ll n, b1, b2;
        cin >> n >> b1 >> b2;
        n -= 2;
        ll nC3 = binomialCoeff(n,3);
        ll term2 = ((n*(n-4)*(n-5))/6);
        cout << nC3 - term2 << endl;




        // int bigad = 0;
        // int bigad2 = 0;

        // if(b1-b2==1||b2-b1==1)
        // {
        //     bigad = 3;
        //     bigad2 = 4; 
        // }
        // else
        // {
        //     bigad = 4;
        //     bigad2 = 6;
        // }
        
        // cout << ((n - bigad) * (n-2)) - (n-bigad2) << endl;


        // mk(arr, n + 1, int);
        // for (int i = 0; i <= n; i++)
        // {
        //     arr[i] = i;
        // }
        // arr[b1] = -1;
        // arr[b2] = -1;
        // int count = 0;
        // vector<ll> v;
        // for (int i = 1; i <= n; i++)
        // {
        //     int j = (i + 1) % n;
        //     // i j
        //     if (arr[i] != -1 && arr[j] != -1)
        //     {
        //         for (int k = 1; k <= n; k++)
        //         {
        //             if ((k != i && k != j))
        //             {
        //                 if (arr[k] != -1)
        //                 {
        //                     auto it = find(v.begin(), v.end(), (i + j + k));
        //                     if (it == v.end())
        //                     {
        //                         v.push_back(i + j + k);
        //                         count++;
        //                     }
        //                     // cout << "i = " << i << " j = " << j << " k = " << k << endl;
        //                 }
        //             }
        //         }
        //     }
        // }
        // cout << count << endl;
    }

    return 0;
}
