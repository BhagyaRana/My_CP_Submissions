#include <bits/stdc++.h>

using namespace std;

#define w(x)    int x; cin>>x; while(x--)
#define endl 	'\n'
#define long long ll
#define mk(arr,n,type)   type *arr=new type[n]

void b_v_r()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

string remove_ctrl_ref_args_it(string const& s) {
    string result;
    result.reserve(s.length());
    for (auto it=s.begin(),end=s.end(); it != end; ++it) {
        if (*it >= 0x20)
            result += *it;
    }
    return result;
}

bool check(string s)
{
    int n = s.size();
    string s1 = "",s2 = "";
    // remove_ctrl_ref_args_it(s1);
    // remove_ctrl_ref_args_it(s2);
    s1.append(s, 0, n/2);
    s2.append(s, (n/2), n); 
    if(s1.compare(s2)==0)
        return true;
    else
        return false;
} 


int main()
{
    b_v_r();
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int len = s.size();
        int i,count = 0;
        string str1 = "",str2 = "";
        for(int j=2;j<=len-2;j+=2)
        {
            // remove_ctrl_ref_args_it(str1);
            // remove_ctrl_ref_args_it(str2);
            str1.append(s,0,j);
            str2.append(s,j,len);
            if(check(str1)&&check(str2)){
                count++;
                cout << str1 << " and " << str2 <<"\n";

            }
            str1.clear();
            str2.clear();
        }
        cout << count << "\n";

        // i = 0 to i = 2 & i = 3 to i = strlen
        // i= 0 to i = 4 & i = 5 to i = strlen
        //  ..  to i = 6 & ..
        //  .. to i = strlen - 2 
        // check  -> true && true 
    }
	

    
    return 0;
}