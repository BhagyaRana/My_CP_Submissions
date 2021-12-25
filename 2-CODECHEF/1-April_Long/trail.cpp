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
		int N;
		cin >> N;
		int a[N], b[N], j = 0, flag = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> a[i];
			if (a[i] == 1)
			{
				b[j] = i;
				j++;
			}
		}
		for (int i = 0; i < j; i++)
		{
			if ((b[i + 1] - b[i]) < 6)
				flag = 1;
		}
		if (flag == 1)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}

	return 0;
}