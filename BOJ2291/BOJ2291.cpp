#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

#define MAX_N 10
#define MAX_M 220
#define MAX_K
#define INF 2000000000
#define MOD

int N,M,K;


int dp(int n, int m, int start)
{
	if (n == N && m == 0)
		return 1;
	else if (n == N || m <= 0)
		return 0;

	int ret = 0;

	for (int i = start; i <= m; i++)
	{
		ret += dp(n + 1, m - i, i);
	}

	return ret;
}

int solve()
{
	int ret = 0;

	return ret;
}

int main(int argc, char** argv)
{
	int tc, T;
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	cin >> T;
	for (tc = 0; tc < T; tc++)
	{
		cin >> N;


		for (int i = 0; i<N; i++)
		{

		}

		cout << solve() << endl;
	}

	return 0;
}