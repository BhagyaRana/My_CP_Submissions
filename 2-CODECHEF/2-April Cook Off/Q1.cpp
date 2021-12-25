#include <bits/stdc++.h>

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
	int n = 0,k =0;
	cin >> n >> k;
	int a[n+1];
	int gfcount = n - 1;
	a[0] = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
	}
	//k is index
	// a[k] has break up
	int num = a[k],newnum = 0;
	for(int i = 1; i <= n ; i++)
	{
		if(a[i]&num)
		{
			if(num!=a[i])
			{
				gfcount--;
				newnum = a[i];
				for(int j=1;j<=n;j++)
				{
					if(a[j]&newnum)
					{
						if(a[j]!=newnum)
							gfcount--;
					}
				}
			}
		}
		num = newnum;
	}
	cout << gfcount << "\n";

	return 0;
}
