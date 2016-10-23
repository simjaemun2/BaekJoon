#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

#define MAX_NM 500
#define INF 2000000000
#define MOD

int N,M;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,1,-1 };

int cache[MAX_NM + 1][MAX_NM + 1];
int input[MAX_NM + 1][MAX_NM + 1];

int solve(int y, int x)
{
	if (y == N - 1 && x == M - 1)
		return 1;

	int &ret = cache[y][x];

	if (ret != -1)
		return ret;

	ret = 0;

	for (int i = 0; i < 4; i++)
	{
		int nextY = dy[i] + y;
		int nextX = dx[i] + x;

		if (0 <= nextY && nextY < N && 0 <= nextX && nextX < M && input[y][x] > input[nextY][nextX])
		{
			ret += solve(nextY, nextX);
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
		scanf("%d %d",&N,&M);
		
		memset(cache, -1, sizeof(cache));

		for (int i = 0; i<N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				scanf("%d",&input[i][j]);
			}
		}

		printf("%d", solve(0, 0));
	}

	return 0;
}