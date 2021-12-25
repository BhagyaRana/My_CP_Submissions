#include <bits/stdc++.h>

using namespace std;

#define mod 			 1000000007//1e9+7 //for question ans%(mod)
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
		int n,oddp = 1;
		unsigned long long a,ans = 0,k=0;
		cin >> n >> a;
		// long long oddp = 1;//oddp + = 2
		// unsigned long long p[n+1] = {0};
		// long long num = a;
		for(int i = 1 ; i <= n ; i++ )
		{
			k = ((unsigned long long)(pow(a,oddp)));
			ans += (k%mod);
			// cout << "Ans"<< i << ans <<"\n";
			a *= k;
			oddp += 2;
		}
		cout << ans%mod << "\n";
	}
	// cout << ((long long)pow(2,1)%mod +(long long) pow(4,3)%mod +(long long) pow(256,5)%mod)%mod;
	return 0;
}
