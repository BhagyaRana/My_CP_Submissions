#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long int ull;

#define mod 			 1000000007
#define inf 			 1e18

#define w(x)    		 int x; cin>>x; while(x--)
#define endl '\n'
#define sz(a) (ll)((a).size())
// #define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define setbits(x) 		 __builtin_popcountll(x)

#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)


void b_v_r()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int Changes(string str, int countA, int countB, int N)
{

	int start = 0;
	int end = N - 1;
	int flipcount = 0;
	if (N == 1)
	{
		return flipcount;
	}
	if (countA >= countB)
	{
		if (str[start] == 'B')
		{
			str[start] = 'A';
			flipcount++;
			while (start < end)
			{
				start++;
				if (str[start] == 'B')
				{
					str[start] = 'A';
					flipcount++;
				}
				if (str[end] == 'B')
					end--;
			}
			return flipcount;

		}
		else
		{
			while (start < end)
			{
				start++;
				if (str[start] == 'B')
				{
					str[start] = 'A';
					flipcount++;
				}
				if (str[end] == 'B')
					end--;
			}
			return flipcount;


		}
	}
	else
	{
		if (str[end] == 'B')
		{
			while (end > start)
			{
				if (str[start] == 'A')
				{
					if (str[start] == 'A')
						start++;
					end--;
					if (str[end] == 'A')
					{
						str[end] = 'B';
						flipcount++;
					}
				}
			}
			return flipcount;

		}
		else
		{
			str[end] == 'B';
			flipcount++;
			while (end > start)
			{
				if (str[start] == 'A')
				{
					if (str[start] == 'A')
						start++;
					end--;
					if (str[end] == 'A')
					{
						str[end] = 'B';
						flipcount++;
					}
				}
			}
			return flipcount;

		}

	}
}


void solve()
{
	w(t)
	{
		int N, countA = 0, countB = 0;
		cin >> N;
		string str;
		getline(cin, str);
		char ch;
		for (int i = 0; i < N; i++)
		{
			ch = str[i];
			if (ch == 'A')
			{
				countA++;
			}
			else
			{
				countB++;
			}
		}
		int ans = Changes(str, countA, countB, N);
		cout << ans << endl;

	}

}

int main()
{
	b_v_r();
	// fast
	// solve();
	cout << "hello";

	return 0;
}
