#include <bits/stdc++.h>

using namespace std;

#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define endl '\n'
// #define mod 1000000007
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
    int n;
    int k;
    cin >> n >> k;
    mk(arr, n, int);
    int mod = (int) (1000000007);
    if (k == 1)
    {
        int m = 1000000007;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int sub = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] > arr[j])
                {
                    sub++;
                }
            }
        }
        cout << sub % m << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int sub = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] > arr[j])
                {
                    sub++;
                }
            }
        }

        int ulta = 0;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(arr[i]>arr[j])
                    ulta++;
            }
        }
        int ans1 = 1;
        int mi = (mod+1)/2; 
        ans1 = ((ans1%mod)*(sub%mod)) % mod;
        ans1 = ((ans1%mod)*(k%mod)) % mod;
        ans1 = ((ans1%mod)*((k+1)%mod)) % mod;
        ans1 = ((ans1%mod)*(mi%mod)) % mod;
        // ans1 = ans1/2; 

        // int t;
        // if(k%2==0)
        // {
        //     t = (((k/2)%mod)*((k+1)%mod))%mod;
        // }
        // else
        // {
        //     t = (((k)%mod)*(((k+1)/2)%mod))%mod;
        // }
        
        // ans1 = (ans1*t) % mod;

        int ans2 = 1;
        ans2 = (ans2*(ulta%mod)) % mod;
        ans2 = ((ans2%mod)*(k%mod)) % mod;
        ans2 = ((ans2%mod)*((k-1)%mod)) % mod;
        ans2 = ((ans2%mod)*(mi%mod)) % mod;

        // ans2 = ans2/2;

        // int t2;
        // if(k%2==0)
        // {
        //     t2 = (((k/2)%mod)*((k+1)%mod))%mod;
        // }
        // else
        // {
        //     t2 = (((k)%mod)*(((k-1)/2)%mod))%mod;
        // }
        // ans2 = (ans2*t2)% mod;
        // cout << ans2 <<"2" <<endl;
        // cout << ans1 << "1" << endl;


        cout << (ans1 + ans2)%mod << endl;
    }

    return 0;
}
