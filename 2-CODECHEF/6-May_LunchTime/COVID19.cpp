#include <bits/stdc++.h>

using namespace std;

#define w(x)    int x; cin>>x; while(x--)
#define endl 	'\n'
#define long long ll
#define mk(arr,n,type)   type *arr=new type[n]

void b_v_r()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int main()
{
	b_v_r();
	w(t)
	{
		short n;
		cin >> n;
		mk(arr, n, int);
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		int flag = 0;
		if (n == 2)
		{
			if (arr[1] - arr[0] > 2)
				cout << "1 1" << endl;
			else
				cout << "2 2" << endl;
		}
		else
		{
			int gmin = n , gmax = 1;
			for (int i = 0; i < n; ++i)
			{
				//arr[i] is infected
				// cout << "index " << i ;
				int j = i, k = i, leftsum = 0, rightsum = 0;
				while (k < n - 1 && arr[k + 1] - arr[k] <= 2)
				{
					rightsum++;
					k++;
				}
				while (j > 0 && arr[j] - arr[j - 1] <= 2)
				{
					leftsum++;
					j--;
				}
				int temp = leftsum + rightsum + 1;
				// cout << " leftsum : " << leftsum << " rightsum : " << rightsum << endl;
				// int min1 = min(leftsum , rightsum );
				// int max1 = max(leftsum , rightsum );
				gmin = min(gmin, temp);
				gmax = max(gmax, temp);
				leftsum = 0; rightsum = 0;
			}
			cout << gmin << " " << gmax << endl;
		}
		// Let first index be infected
		// take min = 1, max = 1
		// while(diff <= 2 ) --> leftsum & rightsum
		// min = min(leftsum,rightsum,min) max=max(max,ls,rs)
	}
	return 0;
}
