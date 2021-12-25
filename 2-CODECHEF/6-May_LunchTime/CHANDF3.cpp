#include <bits/stdc++.h>
#include <map>
#include <iterator>
using namespace std;

#define w(x)    unsigned short int x; cin>>x; while(x--)
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

int main()
{
	b_v_r();
	w(t)
	{
		unsigned long long x, y, z, l, r, i;
		unsigned long long lmax = 0, temp;
		cin >> x >> y >> l >> r;

		int gmax = x | y;
		map<unsigned long long, unsigned long long> gquiz1;
		int flag = 1;

		for (z = l; z <= r; z++)
		{

			if (gmax >= l && gmax <= r)
			{
				cout << gmax << endl;
				flag = 0;
				break;
			}
			else
			{
				i = (x & z) * (y & z);
				cout << "Z = " << z << " i = " << i << endl;
				if (i > lmax)
				{
					lmax = i;

					gquiz1.insert(pair<unsigned long long, unsigned long long>(i, z));
					if (lmax == (x * y))
						break;
				}
			}
		}
		if (flag)
			cout << gquiz1.lower_bound(lmax)->second << endl;
	}
	return 0;

}
