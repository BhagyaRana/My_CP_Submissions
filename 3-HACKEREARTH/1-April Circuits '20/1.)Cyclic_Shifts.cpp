#include <iostream>
#include <bitset>
#include <bits/stdc++.h>

using namespace std;
#define w(x)    		 int x; cin>>x; while(x--)
#define SIZE_INT sizeof(int) * 4


int circularShift(unsigned n, int k, bool leftShift) 
{
	
	if (leftShift)
		return (n << k) | (n >> (SIZE_INT - k));

  	return (n >> k) | (n << (SIZE_INT - k));
}

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
		unsigned N;
		short m;
		char c;
		cin >> N >> m >> c;
		if(c == 'L')
		{
			bitset<16> b(bitset<16>(circularShift(N,m,1)));
			cout << b.to_ulong() << endl;
		}
		else if(c == 'R'){
			bitset<16> b(bitset<16>(circularShift(N,m,0)));
			cout << b.to_ulong() << endl;
		}

	}

	return 0;
}