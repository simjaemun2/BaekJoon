#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

#define MAX_N 100
#define INF 2000000000
#define MOD

typedef long long int LL;

int N;
int input[MAX_N][MAX_N];
LL cache[MAX_N][MAX_N];

LL solve(int y, int x)
{
	LL &ret = cache[y][x];

	if (ret != -1)
		return ret;

	ret = 0;

	if (y + input[y][x] < N)
		ret += solve(y + input[y][x], x);

	if (x + input[y][x] < N)
		ret += solve(y, x + input[y][x]);

	return ret;
}

int main(int argc, char** argv)
{

	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	cin >> N;

	memset(cache, -1, sizeof(cache));


	for (int i = 0; i<N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> input[i][j];
		}
	}

	cache[N - 1][N - 1] = 1;

	cout << solve(0, 0);


	return 0;
}