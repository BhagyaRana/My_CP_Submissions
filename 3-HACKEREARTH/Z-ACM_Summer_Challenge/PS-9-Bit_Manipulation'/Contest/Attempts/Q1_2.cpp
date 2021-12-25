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
typedef unsigned long long ull;
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
int highestPowerOf2(int n) 
{ 
    return (n & (~(n - 1))); 
} 

int main()
{
    b_v_r();
    ull pow2[60];
    // ull sum = 1;
    pow2[0] = 1;
    for (int i = 1; i < 60; i++)
    {
        pow2[i] = pow2[i - 1] * 2;
        // sum += pow2[i];
    }
    // cout << "Sum : " << sum << endl;

    w(t)
    {
        ll n;  // Hunger Requirement
        int m; // No of Elements in Array

        cin >> n >> m;
        ll k = n;

        bitset<60> b(n);
        // cout << "Bitset : "<<b << endl;

        mk(arr, m, ll);

        // vector<pair<ll,ll>> v;
        mk(vis, 60, ll);

        ull sum = 0;
        
        for (int i = 0; i < m; i++)
        {
            cin >> arr[i];
            vis[highestPowerOf2(arr[i])]++;
            sum += arr[i];
        }
        if (sum < n)
        {
            cout << "-1" << endl;
        }
        else
        {
            if (sum == n)
            {
                cout << "0" << endl;
            }
            else
            {
                // sum > n
                ll cuts = 0LL;
                sort(arr, arr + m, greater<int>());
                ll sum = 0LL;
                for (int i = 0; i < m; i++)
                {
                    if (arr[i] > n)
                    {
                        while (arr[i])
                        {
                            arr[i] /= 2;
                            cuts++;
                            if (arr[i] <= n)
                            {
                                n -= arr[i];
                            }
                            if(n==0||n<0)
                            {
                                break;
                            }
                        }
                    }
                    else
                    {
                        if (arr[i] == n)
                        {
                            // cuts = 0;
                            break;
                        }
                        else
                        {
                            //arr[i] < n
                            n -= arr[i];
                        }
                    }
                    if (n == 0)
                        break;
                }
                cout << cuts << endl;
            }
        }
    }

    return 0;
}
