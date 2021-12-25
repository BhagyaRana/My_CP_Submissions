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

// bool isVowel(char c) 
// { 
//     return (c == 'a' || c == 'e' || c == 'i'
//             || c == 'o' || c == 'u'||c == 'A' || c == 'E' || c == 'I'
//             || c == 'O' || c == 'U'); 
// } 
  
// int subString(string str, int n)  
// { 
//     // Pick starting point 
//     int count = 0;
//     vector <int> pos;
//     for(int i=0;i<n;i++)
//     {
//         if(isVowel(str[i]))
//         {
//             pos.push_back(i);
//         }
//     }

//     for (int len = 1; len <= n; len++)  
//     {     
//         // Pick ending point 
//         for (int i = 0; i <= n - len; i++)  
//         { 
//             //  Print characters from current 
//             // starting point to current ending 
//             // point.   
//             int j = i + len - 1;  
//             for(vector<int> ::iterator it= pos.begin();it!=pos.end();it++ )
//             {
//                 //*it <- index
//                 if((*it)<=(j)&&(*it)>=i)
//                     count++;
//             } 
//         } 
//     } 
//     return count;
// } 

int vowel_calc(string s) 
{ 
    int n = s.length(); 
    vector<int> arr; 
  
    for (int i = 0; i < n; i++) { 
  
        if (i == 0) 
            // No. of occurrences of 0th character 
            // in all the substrings 
            arr.push_back(n); 
  
        else
            // No. of occurrences of the ith character 
            // in all the substrings 
            arr.push_back((n - i) + arr[i - 1] - i); 
    } 
  
    int sum = 0; 
    for (int i = 0; i < n; i++) 
  
        // Check if ith character is a vowel 
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i'
            || s[i] == 'o' || s[i] == 'u'||s[i] == 'A' || s[i] == 'E' || s[i] == 'I'
            || s[i] == 'O' || s[i] == 'U') 
            sum += arr[i]; 
  
    // Return the total sum 
    // of occurrences of vowels 
    return sum; 
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
        string str;
        cin.ignore(1, '\n');
        getline(cin, str);
        cout << vowel_calc(str) << endl;
    
    }
    
        
    return 0;
}
