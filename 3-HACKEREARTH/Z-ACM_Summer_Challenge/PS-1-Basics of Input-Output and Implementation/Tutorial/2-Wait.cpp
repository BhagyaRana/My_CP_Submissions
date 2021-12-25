#include <bits/stdc++.h>
using namespace std;

void b_v_r()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int min(int a,int b)
{
    if(a>=b)
        return b;
    else
    {
        return a;
    }
    
}

int main()
{
	b_v_r();
	int t;
    cin >> t;
    while (t--)
    {
        long long a,b,c,d,count = 0;
        cin >> a >> b >> c >> d;
        // 12 = 1 + 2  x
        // 234 = 2 + 3 + 4  y
        // x>1 x+y(b) -> 2 y>3&4
        // a ->   2-a   

        count += a;
        if(c>=(b-a)&&(d>=(b-a)))
            count += (b-a);
        else
        {
            count += min(c,d);
        }
        
        cout << count << "\n";

    }
    
	return 0;
}