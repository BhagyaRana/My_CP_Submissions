#include <bits/stdc++.h>

using namespace std;

#define int 			 short
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
	int t;
	cin >> t;
	int g = t;
	vector <string> c;
	while (t--)
	{
		int N;
		cin >> N;
		int a[N], b[N], j = 0, flag = 2;
		for (int i = 0; i < N; i++)
		{
			cin >> a[i];
			if (a[i] == 1)
			{
				b[j] = i;
				j++;
			}
		}
		for (int i = 0; i < j - 1; i++) //The Costliest Mistake of my Life(j -1 )..accessing memory overflow element
		{
			if ((b[i + 1] - b[i]) < 6)
			{
				c.push_back("NO");
				flag = 1;
				break;
			}
		}
		if (flag != 1)
			c.push_back("YES");


	}
	for (int i = 0; i < c.size(); i++)
		cout << c[i] << endl;

	return 0;
}