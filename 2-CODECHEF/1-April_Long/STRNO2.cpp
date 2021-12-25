#include <iostream>

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
	w(x)
	{
		int x, y;
		cin >> x >> y;
		int t = x;
		int f = 0, z = 2;
		int ans = 0;
		if (x >= y)
		{
			if (y == 1)
			{
				if (x >= 2)
					ans = 1;
			}
			else
			{
				int p = 0;
				for (int i = 2; (i * i) <= x; i++)
				{
					if (x % i == 0)
					{
						p = 1;
						break;
					}
				}

				if (p == 1)
				{
					int pp = 0;
					for (int i = 2; (i * i) <= x; i++)
					{
						while (x % i == 0)
						{
							pp++;
							x = x / i;
						}
					}
					if (x > 2)
					{
						pp++;
					}

					if (pp >= y)
					{
						ans = 1;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}