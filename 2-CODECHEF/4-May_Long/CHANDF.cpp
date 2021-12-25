#include <bits/stdc++.h>
#include <map>
#include <iterator>
using namespace std;

#define w(x)    int x; cin>>x; while(x--)
#define endl 	'\n'
#define ull 	unsigned long long
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
		// cout << "Gmax is " << gmax << endl;
		int flag = 1;
		for (z = l; z <= r; z++)
		{
			// cout << "Z = " << z << " i = " << i << endl;
			if (gmax >= l && gmax <= r)
			{
				cout << gmax << "Gmax" << endl;
				flag = 0;
				// cout << "gmax used;" << endl;
				break;
			}
			else
			{
				i = (x & z) * (y & z);

				if (i > lmax)
				{
					lmax = i;
					// temp = z;
					gquiz1.insert(pair<unsigned long long, unsigned long long>(i, z));
				}
				// map<unsigned long long, unsigned long long>::iterator itr;
				// cout << "\nThe map gquiz1 is : \n";
				// cout << "\tKEY\tELEMENT\n";
				// for (itr = gquiz1.begin() ; itr != gquiz1.end(); ++itr) {
				// 	cout << '\t' << itr->first
				// 	     << '\t' << itr->second << '\n';
				// }
				// cout << endl;
				// cout << "Lmax is " << lmax << endl;

				// if (lmax == (x * y) || z == gmax)
				// {
				// 	cout << z << endl;
				// 	flag = 0;
				// 	break;
				// }
			}
		}
		if (flag)
			cout << "G Quiz Section : " << gquiz1.lower_bound(lmax)->second << endl;

		// lower bound and upper bound for map gquiz1 key = 5
		// cout << "gquiz1.lower_bound(lmax) : "
		//      << "\tKEY = ";
		// cout << gquiz1.lower_bound(lmax)->first << '\t';
		// cout << "\tELEMENT = "

		// if (flag)
		// 	cout << temp << endl;
	}
	return 0;

}
