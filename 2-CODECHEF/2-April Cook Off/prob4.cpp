#include <bits/stdc++.h>
#define int long long
using namespace std;

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
	int n;
	cin >> n;
	int ar1[n];
	for(int i = 0 ; i < n ; i++ )
	{
		cin >> ar1[i];
	}
	int m;
	cin >> m;
	int ar2[m];
	for(int i = 0 ; i < m ; i++ )
	{
		cin >> ar2[i];
	}
	int k = max(n,m);
	int notmax = 0,j=0;
	if(k == m){
		j = n-1;
		notmax = n;
	}
	else{
		j = m-1;
		notmax = m;
	}
	int ar3[k],t =0,carry = 0;
	for(int i = k-1 ; i >=0 ; i--)
	{
		if(notmax == m)
		{

			// j = m - 1;
			if(j>=0)
			{
				t = ar1[i] + ar2[j] + carry;
				ar3[i] = t%10;
				carry = t/10;
				j--;	
			}
			else
			{
				t = ar1[i] + carry;
				ar3[i] = t%10;
				carry = t/10;
			}
			
		}
		else
		{
			// j = n-1;
			if(j>=0)
			{
				t = ar2[i] + ar1[j] + carry;
				ar3[i] = t%10;
				carry = t/10;
				j--;
			}
			else
			{
				t = ar2[i] + carry;
				ar3[i] = t%10;
				carry = t/10;
				
			}
			
		}
		
	}
	for(int i = 0; i < k ; i++)
	{
		cout << ar3[i] <<", ";
	}
	cout<<"END"<<"\n";

	return 0;
}
