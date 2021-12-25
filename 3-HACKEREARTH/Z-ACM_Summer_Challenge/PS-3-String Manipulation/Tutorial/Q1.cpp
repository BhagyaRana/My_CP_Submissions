#include <bits/stdc++.h>
#include<ios> //used to get stream size
#include<limits> //used to get numeric limits

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


#include<iostream> 
#include<cstring> 
using namespace std; 
  
// Function return the total palindromic subsequence 
int countPS(string str) 
{ 
    int N = str.length(); 
  
    // create a 2D array to store the count of palindromic 
    // subsequence 
    int cps[N+1][N+1]; 
    memset(cps, 0 ,sizeof(cps)); 
  
    // palindromic subsequence of length 1 
    for (int i=0; i<N; i++) 
        cps[i][i] = 1; 
  
    // check subsequence of length L is palindrome or not 
    for (int L=2; L<=N; L++) 
    { 
        for (int i=0; i<N; i++) 
        { 
            int k = L+i-1; 
            if (str[i] == str[k]) 
                cps[i][k] = cps[i][k-1] + 
                            cps[i+1][k] + 1; 
            else
                cps[i][k] = cps[i][k-1] + 
                            cps[i+1][k] - 
                            cps[i+1][k-1]; 
        } 
    } 
  
    // return total palindromic subsequence 
    return cps[0][N-1]; 
} 


void b_v_r()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int main()
{
    b_v_r();
    w(t)
    {
        // cin.ignore('256','\n');
        int n;
        cin >> n;
        // cin.ignore(256, '\n');
        string str;
        // getline(cin, str);
        cin >> str;
        cout<< countPS(str) << endl;
        

    }
    
        
    return 0;
}
