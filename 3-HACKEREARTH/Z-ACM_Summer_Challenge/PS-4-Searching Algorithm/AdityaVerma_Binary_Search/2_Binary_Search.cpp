#include <bits/stdc++.h>

using namespace std;

#define w(x)    int x; cin>>x; while(x--)
#define endl 	"\n"
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define rep(i,n) for (i = 0; i < n; ++i)
#define REP(i,k,n) for (i = k; i <= n; ++i)
#define REPR(i,k,n) for (i = k; i >= n; --i)
typedef long long ll;
#define mk(arr,n,type)   type *arr=new type[n]
const int mod=1000000007;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}

void b_v_r()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int BinarySearch(int arr[], int n, int ele)
{
    int start = 0;
    int end = n - 1;
    int res = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == ele)
        {
            res = mid;
            // For First Occurance
            end = mid - 1;
            // For Last Occurance
            // start = mid + 1;
        }
        else
        {
            if (ele < arr[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
    }
    return res; 
}

int main()
{
    b_v_r();
    w(t)
    {
        int n;
        cin >> n;
        mk(arr,n,int);
        int i = 0;
        rep(i, n)
        {
            cin >> arr[i];
        }
        int element;
        cin >> element;
        int ans = BinarySearch(arr, n, element);
        cout << "Found at " << ans << endl;
    }
    
        
    return 0;
}
