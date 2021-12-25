#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long int ull;

#define mod 			 998244353

#define endl '\n'
#define sz(a) (ll)((a).size())
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define setbits(x) 		 __builtin_popcountll(x)

#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)



void b_v_r()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

void printSubArrays(vector<int> arr, int start, int end)
{
	// Stop if we have reached the end of the array
	if (end == arr.size())
		return;

	// Increment the end point and start from 0
	else if (start > end)
		printSubArrays(arr, 0, end + 1);

	// Print the subarray and increment the starting point
	else
	{
		cout << "[";
		for (int i = start; i < end; i++) {
			cout << arr[i] << ", ";
		}

		cout << arr[end] << "]" << endl;
		printSubArrays(arr, start + 1, end);
	}

	return;
}

int main()
{
	b_v_r();
	fast;
	short t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> v1;
		rep(i, n)
		{
			int a;
			cin >> a;
			v1.push_back(a);
		}
		printSubArrays(v1, 0, 0);


	}
	return 0;
}
