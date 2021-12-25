#include <bits/stdc++.h>

using namespace std;

#define w(x)    int x; cin>>x; while(x--)
#define endl 	"\n"
#define rep(i,n) for (i = 0; i < n; ++i)
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

// How many Times array is Rotated
// 1.) No of Times Array is Rotated = Index of Smallest Element
// 2.) Both of Neighbours Se Smaller
// 3.) Go to Unsorted Side
// Returns Index Of Minimum Element
int BinarySearchRotated(int arr[], int n, int ele)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int next = (mid+1)%n; //last index
        int prev = (mid-1+n)%n; //0 index outofbound
        if (arr[mid]<arr[next]&&arr[mid]<arr[prev])
            return mid;
        else
        {
            if (arr[start] < arr[mid])
                start = mid + 1;
            else
                end = mid - 1; //arr[mid]<arr[end]
        }
    }
    return -1; //Not Found Case
} 
 

int BinarySearch(int arr[],int st,int en,int ele)
{
    int start = st;
    int end = en;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == ele)
            return mid;
        else
        {
            if (ele < arr[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
    }
    return -1; //Not Found Case
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
        int min_index = BinarySearchRotated(arr, n, element);
        int ans1 =  BinarySearch(arr,0,min_index-1,element);
        int ans2 = BinarySearch(arr,min_index,n-1,element);
        if(ans1==-1&&ans2==-1)
            cout<<"Not Found";
        else
            {
                if(ans1==-1)
                    cout<<"Found : "<<ans2;
                else
                {
                    cout<<"Found : "<<ans1;
                }
                
            }
    }
    
        
    return 0;
}
