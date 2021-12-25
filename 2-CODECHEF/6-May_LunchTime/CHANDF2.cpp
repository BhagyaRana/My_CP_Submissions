#include <bits/stdc++.h>

using namespace std;

#define w(x)    int x; cin>>x; while(x--)
#define endl 	'\n'
#define mk(arr,n,type)   type *arr=new type[n];

void b_v_r()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
// If there is more than one such value of Z, he should find the smallest one in the range

int main()
{
	b_v_r();
	w(t)
	{
		unsigned long long x, y, z = 0, l, r, lmax = 0, temp = 0;
		cin >> x >> y >> l >> r;
		int gmax = x | y;
		// cout << "Gmax is " << gmax << endl;
		int flag = 1;
		if (gmax >= l && gmax <= r)
		{
			cout << gmax << endl;
			flag = 0;
		}
		unsigned long long j = 0;
		if (flag)
		{
			for (z = l; z <= r; z++)
			{
				unsigned long long i = ((x & z) * (y & z));
				// cout << "Z = " << z << " i = " << i << endl;
				if (i > lmax)
				{
					lmax = i;
					// temp = z;
				}
			}
			for (z = l; z <= r; z++)
			{
				unsigned long long j = ((x & z) * (y & z));
				if (j == lmax)
				{
					cout << z << endl;
					continue;
				}
			}
		}
	}
	return 0;
}
