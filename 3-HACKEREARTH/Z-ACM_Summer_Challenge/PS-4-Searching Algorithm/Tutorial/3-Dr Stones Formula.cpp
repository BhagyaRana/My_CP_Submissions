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


void calcFib(vector<int>& Fib, int K) 
{ 
    int i = 3, nextTerm; 
    Fib.push_back(0); 
    Fib.push_back(1); 
    Fib.push_back(1); 
    while (1) { 
        nextTerm = Fib[i - 1] + Fib[i - 2]; 
        if (nextTerm > K) 
            return; 
        Fib.push_back(nextTerm); 
        i++; 
    } 
} 
  
int findMinTerms(int K) 
{ 
  
    vector<int> Fib; 
    calcFib(Fib, K); 
    int count = 0, j = Fib.size() - 1; 
    while (K > 0) { 
          
        count += (K / Fib[j]); 
        K %= (Fib[j]); 
  
        j--; 
    } 
    return count; 
} 

int main()
{
    b_v_r();
    w(t)
    {
        int n;
        cin >> n;
        cout << findMinTerms(n) << endl;
    }
    
        
    return 0;
}
