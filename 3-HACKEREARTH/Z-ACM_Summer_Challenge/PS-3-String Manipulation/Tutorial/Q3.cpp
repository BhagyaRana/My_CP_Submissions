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

vector<string> splitStrings(string str, char dl) 
{ 
    string word = ""; 
  
    // to count the number of split strings 
    int num = 0; 
  
    // adding delimiter character at the end 
    // of 'str' 
    // str = str + dl; 
  
    // length of 'str' 
    int l = str.size(); 
    int flag = 2;
    bool ok = true;
    size_t pos = str.find("//");
    string sub = str.substr(pos);


    // traversing 'str' from left to right 
    vector<string> substr_list; 
    for (int i = 0; i < l; i++) { 
  
        // if str[i] is not equal to the delimiter 
        // character then accumulate it to 'word' 
        if (str[i] != dl ) 
        {
                word = word + str[i]; 
           
        }
        else { 
  
            // if 'word' is not an empty string, 
            // then add this 'word' to the array 
            // 'substr_list[]' 
            if(i+1<l)
                if(str[i+1]=='/')
                    {
                        if(substr_list.size()!=0)
                            substr_list.pop_back();
                        int j = i; 
                        while(str[j]!='/')
                        {
                            j++;
                        }
                        i = j;
                    }
            if ((int)word.size() != 0) 
                substr_list.push_back(word); 
  
            // reset 'word' 
            word = ""; 
        } 
    } 
  
    // return the splitted strings 
    return substr_list; 
} 

int main()
{
    b_v_r();

    w(q)
    {
        string str;
        cin.ignore(1, '\n');
        getline(cin, str);
        char dl = '/';
        
        // int n = str.size();
        // for(int i=0;i<n;i++)
        // {
        //     if(str[i]=='/')
        //     {
        //         for(int j=i+1; )
        //     }
        // }
    }
        
    return 0;
}
