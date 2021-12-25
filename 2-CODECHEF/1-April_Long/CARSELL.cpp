#include <bits/stdc++.h>

using namespace std;


// #define int 			 long long
#define mod 			 1000000007


void b_v_r()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
vector <int> c;

int32_t main()
{
	b_v_r();
	short t;
	cin >> t;
	while (t--)
	{
		int N, profit = 0;
		cin >> N;
		int yr = N;
		long long a[N];
		for (int i = 0; i < N; i++)
		{
			cin >> a[i];
		}
		int n = sizeof(a) / sizeof(a[0]);
		sort(a, a + n, greater<int>());
		//Code Optimized !! Hurray
		profit = a[0];
		for (int i = 1; i < yr; i++)
		{	if (a[i] - i > 0)
			{
				int k = ((a[i] % mod) - (i % mod)) % mod;
				profit = ((profit % mod) + (k % mod)) % mod;

			}
		}
		// (a[i]-yr)%mod =
		// int j = 0;
		// while (yr--)
		// {

		// 	profit = ((profit % mod) + (a[j] % mod)) % mod;
		// 	j = j + 1;
		// 	// for (int i = 0; i < n; i++)
		// 	// {
		// 	// 	if (a[i] > 0)
		// 	// 		a[i] -= 1;
		// 	// }
		// 	for (int i = 0; i< n; i++)
		// 	{

		// 	}
		// }
		c.push_back(profit);
	}
	for (int i = 0; i < c.size(); i++)
		cout << c[i] << endl;

	return 0;
}