#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

#define MAX_N 50
#define MOD 1000000007

typedef int LL;

int N,A,B,C;
LL cache[MAX_N+1][MAX_N+1][MAX_N+1][MAX_N+1];

LL solve(int n, int a, int b, int c)
{
	if (n == 0)
	{
		if (a == 0 && b == 0 & c == 0)
			return 1;
		return 0;
	}

	if (a < 0 || b < 0 || c < 0)
		return 0;

	if (a + b + c < n)
		return 0;

	LL &ret = cache[n][a][b][c];

	if (ret != -1)
		return ret;

	ret = solve(n-1,a-1,b-1,c-1);
	ret %= MOD;
	ret += solve(n - 1, a - 1, b, c);
	ret %= MOD;
	ret += solve(n - 1, a, b - 1, c);
	ret %= MOD;
	ret += solve(n - 1, a, b, c - 1);
	ret %= MOD;
	ret += solve(n - 1, a - 1, b-1, c);
	ret %= MOD;
	ret += solve(n - 1, a - 1, b, c-1);
	ret %= MOD;
	ret += solve(n - 1, a, b - 1, c - 1);
	ret %= MOD;

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
		memset(cache, -1, sizeof(cache));
		cin >> N >> A >> B >> C;

		cout << solve(N,A,B,C) << endl;
	}

	return 0;
}