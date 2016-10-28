#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

#define MAX_N 100
#define INF 2000000000
#define MOD 10

int N;

int c[MAX_N + 2];
int f[MAX_N + 2];

int cache[MAX_N+1][10][10][10][2];

int mod(int n)
{
	if (n >= 0)
		return n%MOD;
	if (-n%MOD == 0)
		return 0;
	return MOD - (-n%MOD);
}

int dp(int index, int s0, int s1,int s2, int isplus)
{
	if (index == N)
		return 0;

	int &ret = cache[index][s0][s1][s2][isplus];

	if (ret != -1)
		return ret;

	if (mod(c[index] + s0) == f[index])
		return ret = min(dp(index + 1, s1, s2, 0,0), dp(index + 1, s1, s2,0 ,1));

	ret = INF;

	for (int i = 1; i <= 3; i++)
	{
		ret = min(ret, 1+dp(index, mod(s0 + i), s1, s2,1));
		ret = min(ret, 1+dp(index, mod(s0 - i), s1, s2,0));
		if (index < N - 1)
		{
			ret = min(ret, 1+dp(index, mod(s0 + i), mod(s1 + i), s2,1));
			ret = min(ret, 1+dp(index, mod(s0 - i), mod(s1 - i), s2,0));
		}
		if (index < N - 2)
		{
			ret = min(ret, 1+dp(index, mod(s0 + i), mod(s1 + i), mod(s2 + i),1));
			ret = min(ret, 1+dp(index, mod(s0 - i), mod(s1 - i), mod(s2 - i),0));
		}
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
		scanf("%d", &N);

		memset(cache, -1, sizeof(cache));

		for (int i = 0; i < N; i++)
		{
			scanf("%1d", &f[i]);
		}

		for (int i = 0; i < N; i++)
		{
			scanf("%1d", &c[i]);
		}

		printf("%d", min(dp(0, 0, 0, 0,0), dp(0, 0, 0,0, 1)));
	}

	return 0;
}
