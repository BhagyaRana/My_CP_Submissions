#include <bits/stdc++.h>

using namespace std;

#define int 			 long long
#define mod 			 1000000007
#define inf 			 1e18
#define w(x)    		 int x; cin>>x; while(x--)
#define fi(i,a,b) 		 for(int i=0;i<b; i++)
#define pb push_back

void b_v_r()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
void solve()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> a(n);
	fi(i, 0, n)
	{
		fi(j, 0, k)
		{
			int x;
			cin >> x;
			a[i].pb(x);
		}
	}
	fi(i, 0, n)
	{
		cout << a[i][0] << " ";
	}
	cout << endl;
}

int32_t main()
{
	b_v_r();
	w(x)
	{
		solve();
	}
	return 0;
}