#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define MAX_N 100
#define MAX_K 1000000010
int N,M,K;

int bino[MAX_N*2 + 2][MAX_N*2 + 2];

void calcBino()
{
	for (int i = 0; i <= N+M; i++)
	{
		bino[i][0] = bino[i][i] = 1;

		for (int j = 1; j < i; j++)
			bino[i][j] = min(MAX_K,bino[i - 1][j - 1] + bino[i - 1][j]);
	}
}

string solve(int n, int m, int skip)
{
	if (n == 0)
		return string(m, 'z');

	if (skip <= bino[n + m - 1][n - 1])
		return "a" + solve(n - 1, m, skip);
	return "z" + solve(n, m - 1, skip - bino[n + m - 1][n - 1]);
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
		cin >> N >> M >> K;
		
		calcBino();

		if (bino[N + M][N] < K)
			cout << -1;
		else
			cout << solve(N, M, K);
	}

	return 0;
}