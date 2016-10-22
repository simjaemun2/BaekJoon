#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

#define MOD 9901
#define MAX_N 100000

int N;
int cache[MAX_N + 1][3];

/*
prev state : Àü ÁÙ
0 - ¾øÀ½
1 - 1¹øÄ­
2 - 2¹øÄ­
*/

int solve(int n, int prev)
{
	if (n == N)
		return 1;

	int &ret = cache[n][prev];

	if (ret != -1)
		return ret;
	
	ret = solve(n + 1, 0) % MOD;

	if (prev != 2)
	{
		ret += solve(n + 1, 2);
		ret %= MOD;
	}
		

	if (prev != 1)
	{
		ret += solve(n + 1, 1);
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
	T = 1;

	for (tc = 0; tc < T; tc++)
	{
		cin >> N;

		memset(cache, -1, sizeof(cache));

		cout << solve(0,0) << endl;
	}

	return 0;
}