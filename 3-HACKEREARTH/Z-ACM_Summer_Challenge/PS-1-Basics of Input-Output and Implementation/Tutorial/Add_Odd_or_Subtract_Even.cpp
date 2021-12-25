#include <bits/stdc++.h>
using namespace std;

int steps(int a,int b)
{
    int step = 0;
    if(a==b)  
        return step;  //  Case 1 : a = b  
    else
    {
        if(a>b)
        {
            if((a-b)%2==0)
            {
                 step = 1;
                 return step;
            }
            else
            {
                step = 2;
                return step;
            }
        }
        else
        {
            if((b-a)&1)
                {
                    step = 1;
                    return step;
                }
            else
            {
                step = 2;
                return step;
            }     
        }
        
    }
    
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,a,b;
    cin >> t;
    while(t--)
    {
       cin >> a >> b;
       cout<<steps(a,b)<<"\n";
    }
    return 0;
}