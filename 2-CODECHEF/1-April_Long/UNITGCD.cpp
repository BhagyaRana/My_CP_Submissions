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

int32_t main()
{
	b_v_r();
	w(t)
	{
		int x;
		cin >> x;
		if (x == 1) {
			cout << 1 << endl << "1 1" << endl;
		}
		else if (x == 2) {
			cout << 1 << endl << "2 1 2" << endl;
		}
		else if (x == 3)
		{
			cout << (x / 2) << endl << "3 1 2 3" << endl;
		}
		else
		{
			cout << (x / 2) << endl << "3 1 2 3" << endl;

			string s;
			for (int i = 2; i < (x / 2); i++)
			{
				s += "2 " + to_string(i * 2) + " " + to_string((i * 2) + 1) + "\n";
			}
			cout << s;
			if (x % 2 == 0)
			{
				cout << "1 " << x;
			}
			else
			{
				cout << "2 " << (x - 1) << " " << x;
			}
			cout << endl;
		}

	}
	return 0;
}