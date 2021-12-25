#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long int ull;

#define mod 			 1000000007
#define inf 			 1e18

#define w(x)    		 int x; cin>>x; while(x--)
#define endl '\n'
#define sz(a) (ll)((a).size())
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define setbits(x) 		 __builtin_popcountll(x)


void b_v_r()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}



int main()
{
	b_v_r();
	fast;
	w(t)
	{
		int n, k;
		cin >> n >> k;
		int arr[n + 1];
		arr[0] = -1;
		for (int i = 1 ; i < n + 1; i++)
		{
			cin >> arr[i];
		}
		// int newarr[n+1];
		// newarr[0]=-1;
		for (int i = 1 ;  (i + k) < n + 1; i++)
		{
			if (arr[i + k] < arr[i])
			{
				int temp = arr[i];
				arr[i] = arr[i + k];
				arr[i + k] = temp;
			}

		}
		int count = 0;
		for (int i = 1; i < n + 1; i++)
		{
			if (arr[i + 1] < arr[i])
			{
				cout << "no" << endl;
				break;
			}
			else
			{
				count++;
			}
		}
		if (count == n)
		{
			cout << "yes" << endl;
		}

	}
	return 0;
}
