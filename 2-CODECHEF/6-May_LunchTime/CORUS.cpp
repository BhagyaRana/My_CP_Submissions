#include <bits/stdc++.h>
// Very Big Mistake of Not Iterating over All Elements
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
int main()
{
	b_v_r();
	w(t)
	{
		long long N, Q;
		cin >> N >> Q;
		string str;
		cin >> str;
		//Precomputing Frequency Table ,'freq[]' implemented as hash table
		long long freq[26];
		memset(freq, 0, sizeof(freq));
		for (long long i = 0; i < N; i++)
			freq[str[i] - 'a']++;
		long long max = -1;
		for (int i = 0; i < 26; i++)
		{
			// cout << "i = " << i << " and freq[i] = " << freq[i] << endl;
			if (freq[i] > max)
				max = freq[i];
		}
		long long count = 0;
		for (long long j = 0; j < Q; j++)
		{
			long long c;
			cin >> c;
			if (c >= max)
			{
				cout << "0" << endl;
				continue;
			}
			else
			{
				for (int i = 0; i < 26; i++)
				{
					if ((freq[i] - c) > 0)
						count += (freq[i] - c);
				}
				cout << count << endl;
				count = 0;
			}
		}
	}
	return 0;
}
