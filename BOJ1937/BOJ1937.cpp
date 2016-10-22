#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

#define MAX_N 500

int N;

int input[MAX_N][MAX_N];
int cache[MAX_N][MAX_N];

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

int solve(int y, int x)
{
	int &ret = cache[y][x];

	if (ret != -1)
		return ret;
	ret = 1;

	for (int i = 0; i < 4; i++)
	{
		int nextX = dx[i] + x;
		int nextY = dy[i] + y;

		if (0 <= nextX && nextX < N && 0 <= nextY && nextY < N && input[y][x] < input[nextY][nextX])
		{
			ret = max(ret, solve(nextY, nextX) + 1);
		}
			
	}

	return ret;
}

int main(int argc, char** argv)
{
	int tc, T;
	std::ios::sync_with_stdio(false);

	T = 1;
	for (tc = 0; tc < T; tc++)
	{
		cin >> N;

		memset(cache, -1, sizeof(cache));

		for (int i = 0; i<N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> input[i][j];
			}
		}

		int ans = 0;

		for (int i = 0; i<N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				ans = max(ans, solve(i, j));
			}
		}

		cout << ans << endl;
	}

	return 0;
}