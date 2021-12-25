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

    // Floor and Ceil Of Element
int BinarySearch(int arr[], int st,int ed, int ele)
{
    int start = st;
    int end = ed;
    int res = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == ele)
            return mid;
        else
        {
            if (ele < arr[mid])
            {
                // Ceil of Element
                // res = arr[mid];
                end = mid - 1;
            }
            else
            { //arr[mid] < ele
                // Floor of Element
                res = mid;
                start = mid + 1;
            }
        }
    }
    return res; //Not Found Case
}
     
    int main()
    {
        b_v_r();
        w(t)
        {
            int n,ans = 0;
            cin >> n;
            mk(arr, n , int);
            int i = 0,j;
            rep(i,n)
            {
                cin >> arr[i];
            }
            for(int i=1;i<n;i++)
            {
                int cnt = 0;
                if(arr[i]<arr[0])
                    cnt += i;
                else
                {
                    if(arr[i]>=arr[i-1])
                        cnt += 0;
                    else
                    {
                        int k = BinarySearch(arr,0,i-1,arr[i]); //index
                        cnt += (i-k-1);
                    } 
                }
                
                // for( j=i-1;j>=0;j--)
                // {
                //     if(arr[j]>arr[i])
                //         cnt++;
                // }
                ans += cnt;
                sort(arr, arr + i);

            }
            cout<<ans<<endl;
     
        }
            
        return 0;
    }