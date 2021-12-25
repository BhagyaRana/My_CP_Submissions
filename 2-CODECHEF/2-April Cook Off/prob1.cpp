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
		long int n,q;
		cin >> n >> q;
		long int fcount = 0;
		int start = 0;
		while(q--)
		{
			long int fi,di;
			cin >> fi >> di;
			fcount += (abs(di-fi) + abs(fi-start));
			start = di;
		}
		cout << fcount << "\n";
	}

	return 0;
}
