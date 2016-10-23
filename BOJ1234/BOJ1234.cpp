#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

#define MAX_N 10
#define MAX_M 100
#define INF 2000000000
#define MOD

typedef long long int LL;

int N, R, G, B;
LL cache[MAX_N + 1][MAX_M + 1][MAX_M + 1][MAX_M + 1];
LL fac[MAX_N + 1];


LL solve(int n, int r, int g, int b)
{
	if (n == 0)
		return 1;

	LL &ret = cache[n][r][g][b];

	if (ret != -1)
		return ret;

	ret = 0;

	if (r >= n)
		ret += solve(n - 1, r - n, g, b);
	if (g >= n)
		ret += solve(n - 1, r, g - n, b);
	if (b >= n)
		ret += solve(n - 1, r, g, b - n);;

	if (n % 2 == 0)
	{
		if(r >= n/2 && g >= n/2)
			ret += fac[n]/fac[n/2]/fac[n/2]* solve(n - 1, r - n/2, g - n/2, b);
		if (r >= n/2 && b >= n/2)
			ret += fac[n] / fac[n/2] / fac[n/2] * solve(n - 1, r - n/2, g, b - n/2);
		if (b >= n/2 && g >= n/2)
			ret += fac[n] / fac[n/2] / fac[n/2] * solve(n - 1, r, g - n/2, b - n/2);
	}

	if (n % 3 == 0)
	{
		if (r >= n/3 && g >= n/3 && b >= n/3)
			ret += fac[n] / fac[n/3] / fac[n/3] / fac[n/3] * solve(n - 1, r - n/3, g - n/3, b - n/3);
	}

	return ret;
}

int main(int argc, char** argv)
{
	int tc, T;
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	//cin >> T;
	T = 1;
	for (tc = 0; tc < T; tc++)
	{
		cin >> N>> R>> G>> B;

		memset(cache, -1, sizeof(cache));


		fac[0] = fac[1] = 1L;
		for (int i = 2; i <= N; i++)
		{
			fac[i] = i*fac[i - 1];
		}

		cout << solve(N, R, G, B) << endl;
	}

	return 0;
}