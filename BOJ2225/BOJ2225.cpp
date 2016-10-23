#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

#define MAX_N 200
#define MAX_K 200
#define INF 2000000000
#define MOD 1000000000

int N, K;
int cache[MAX_N + 1][MAX_K + 1];

int solve(int n, int k)
{
	if (k < 0)
		return 0;

	if (k == 0)
	{
		if (n == 0)
			return 1;
		return 0;
	}

	int &ret = cache[n][k];

	if (ret != -1)
		return ret;
	ret = 0;

	for (int i = 0; i <= n; i++)
	{
		ret += solve(n - i, k - 1);
		ret %= MOD;
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
	memset(cache, -1, sizeof(cache));
	T = 1;
	for (tc = 0; tc < T; tc++)
	{
		cin >> N >> K;

		cout << solve(N, K) << endl;
	}

	return 0;
}