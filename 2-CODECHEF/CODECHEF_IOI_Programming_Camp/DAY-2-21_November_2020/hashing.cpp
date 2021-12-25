#include <bits/stdc++.h>
#include <iostream>
#include <string>
const int N = 1e6 + 6;

const int mod = 1e9 + 7;
const int base = 33;

int add(int a, int b, int mod)
{
	int res = (a + b) % mod;
	if (res < 0)
		res += mod;
	return res;
}

int mult(int a, int b, int mod)
{
	int res = (a * 1LL * b) % mod;
	if (res < mod)
		res += mod;
	return res;
}

int power(int a, int b, int mod)
{
	int res = 1;
	while (b)
	{
		if ((b % 2) == 1)
			res = mult(res, a, mod);
		a = mult(a, a, mod);
		b /= 2;
	}
	return res;
}

int pw[N];
int inv[N];
int hash[N];

void precalc()
{
	pw[0] = 1;
	for (int i = 1; i < N; i++)
		pw[i] = mult(pw[i - 1], base, mod);

	int pw_inv = power(base, mod - 2, mod);
	inv[0] = 1;
	for (int i = 1; i < N; i++)
		inv[i] = mult(inv[i - 1], pw_inv, mod);
}

void build(string s)
{
	int n = s.length();
	for (int i = 0; i < n; ++i)
	{
		hash[i] = add((i == 0) 0 ? hash[i - 1], mult(pw[i], s[i] - 'a' + 1, mod), mod);
	}
}

int getHash(int x, int y)
{
	int res = add(hash[y], (x == 0) ? 0 : -hash[x - 1], mod);
	res = mult(res, (x == 0) ? 1 : inv[x - 1], mod);
	return res;
}