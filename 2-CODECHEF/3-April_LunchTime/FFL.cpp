/*@author: Bhagya Rana*/
#include <bits/stdc++.h>
using namespace std;
//to ans multiple test cases
#define w(x)    		 int x; cin>>x; while(x--)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl '\n'

void b_v_r()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}


int32_t main()
{
	b_v_r();
	fast;
	short t;
	cin >> t;
	while (t--)
	{
		short n, s;
		cin >> n >> s;
		short p[n];
		short forw[n];
// 		short d[n + 1];
// 		short f[n + 1];
		for (short i = 0 ; i < n; i++)
		{
			cin >> p[i];
		}
		// short j = 0, k = 0;
		int min1 = INT_MAX, min2 = INT_MAX;
		for (short i = 0 ; i < n ; i++)
		{
			cin >> forw[i];
			if (forw[i])
			{
				if (p[i] < min1)
					min1 = p[i];
				// f[j] = p[i];
				// j++;
			}
			else
			{
				if (p[i] < min2)
					min2 = p[i];
				// d[k] = p[i];
				// k++;
			}
			if (s + min1 + min2 > 100)
			{
				cout << "no" << "\n";
				break;
			}
		}
		// short n1 = sizeof(d) / sizeof(d[0]), n2 = sizeof(f) / sizeof(f[0]);
		// sort(d, d + n1); sort(f, f + n2);
		// cout << d[0] << " and " << f[0] << endl;
		if (s + min1 + min2 <= 100)
			cout << "yes" << endl;
	}
	return 0;
}
