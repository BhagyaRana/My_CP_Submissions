#include <bits/stdc++.h>
using namespace std;
#define ll long long
void b_v_r()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
ll powerc(ll n) {

	ll p = 0;
	while (n != 0) {

		n = n / 2;  p++;
	}
	return p;
}

ll setbit(ll n) {

	ll count = 0;

	while (n) {

		n &= (n - 1);   count++;
	}
	return count;
}

int main() {

	b_v_r();

	int tt;  cin >> tt;

	while (tt--)
	{

		ll x, y, l, u;   cin >> x >> y >> l >> u;
		ll z, set = 0;

		z = x | y;

		if (z >= l && z <= u)
			cout << z << endl;
		else if (z > u) {

			ll pz = 0, pu = 0;

			pz = powerc(z);
			pu = powerc(u);

			if (pz == pu) {

				ll count, mask = 0, tpz;
				tpz = pz;
				count = setbit(z);
				while (tpz >= 0)
				{
					if (z & (1 << (tpz - 1))) {

						mask |= (1 << (tpz - 1)); set++;

						if (!(mask >= pow(2, pu - 1) && mask <= u)) {
							mask &= ~(1 << tpz - 1); set--;

						}
					}
					--tpz;
				}
				if (set == pz - 1)
					cout << mask << endl;
				else {
					z = z & ~(1 << (pz - 1));
					cout << z << endl;
				}

			} else {
				z = z & ~(1 << (pz - 1));
				cout << z << endl;
			}
		}

	}
	return 0;
}