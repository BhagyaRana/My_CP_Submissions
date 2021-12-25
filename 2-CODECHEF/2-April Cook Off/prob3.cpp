#include <bits/stdc++.h>

using namespace std;

#define w(x)    		 int x; cin>>x; while(x--)


void b_v_r()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}


int32_t main()
{
	b_v_r();
	w(t)
	{
		string s;string r;
		cin >> s;
		cin >> r;
		int n = s.size(),l=0,k = 0;
		for(int i=0;i<n;i++)
		{
			int a = i,b;
			if(s[i]!=r[i])
			{
				s[i] = r[i];
				l++;
				if(s[i+1]==r[i+1]&&(i+1)<n)
				{
					b=i;
				}
				else
				{
					if(i+1<n)
					{
						int j = 1;
						while(s[i+j]!=r[i+j]&&(i+j)<n)
						{
							l++;
							s[i+j] = r[i+j];
							j++;
						}
						b = j - 1;
						cout << "b = "<<b << endl;
						i = b;
					}
					else
					{
						b = i;
					}
					
				}
				k += (b-a+1);
				// cout<<"k value " << k << "\n";
				// cout<<"l value " << l << "\n";

			}
		}
		// if(s == r)
		// {
		// 	cout << "Equal" << endl;
		// } 
		cout << k*l << "\n";
	}

	return 0;
}
