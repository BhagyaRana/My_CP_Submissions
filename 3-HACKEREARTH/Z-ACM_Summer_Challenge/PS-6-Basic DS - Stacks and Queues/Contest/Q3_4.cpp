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

bool compare(string a, string b) 
{ 
    return (a+b < b+a); 
} 
  
string lexSmallest(string a[], int n) 
{ 
    // Sort strings using above compare() 
    sort(a, a+n, compare); 
  
    // Concatenating sorted strings 
    string answer = ""; 
    for (int i = 0; i < n; i++) 
        answer += a[i]; 
  
    return answer; 
} 

int main()
{
    b_v_r();
    
    string str;
    cin >> str;
    int n = str.length();
    char string[n];
    for(int i=0;i<n;i++)
    {
        string[i] = str[i];
    }
    cout << lexSmallest(string[],n);

    // int freq[26];
    // memset(freq, 0, sizeof(freq));

    // int k = str.length();

    // for (int i = 0; i < k; i++)
    //     freq[str[i] - 'a']++;
    
    
    // for(int i=0;i<k;i++)
    // {

    // }

        
    return 0;
}
