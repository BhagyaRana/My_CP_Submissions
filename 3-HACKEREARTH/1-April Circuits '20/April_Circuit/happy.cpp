#include <bits/stdc++.h>

using namespace std;

#define w(x)    		 int x; cin>>x; while(x--)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,n) for(int i=0;i<(n);++i)

void b_v_r()
{
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int main()
{
	b_v_r();
	int n, m;
	cin >> n >> m;
	int arr[n], h[m];
	rep(i, n)
	{
		cin >> arr[i];
	}
	rep(i, m)
	{
		cin >> h[i];
	}
	short q;
	cin >> q;
	while (q--)
	{
		int l, r, count = 0;
		int flag = 1, temp = 1;
		cin >> l >> r;
		int vis[m + 1] = {0};
		for (int i = l - 1; i < r; i++)
		{
			vis[arr[i]]++;
		}
		for (int i = l - 1; i < r ; i++)
		{
			if (vis[arr[i]] != arr[i])
			{
				cout << "0" << endl;
				break;
			}
			else
			{
				count++;
			}
		}
		if (count == (r - l + 1))
			cout << "1" << endl;

	}

	return 0;
}
