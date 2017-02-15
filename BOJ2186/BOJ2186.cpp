#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <memory.h>

using namespace std;

#define MAX_NM 100
#define MAX_W 80

int N, M, K;
char input[MAX_NM][MAX_NM + 1];
char w[MAX_W + 1];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int cache[MAX_NM][MAX_NM][MAX_W];

int dfs(int y, int x, int n)
{
	if (!w[n + 1])
	{
		return 1;
	}

	int& ret = cache[y][x][n];

	if (ret != -1)
		return ret;

	ret = 0;

	for (int d = 0; d < 4; d++)
	{
		for (int k = 1; k <= K; k++)
		{
			int nx = x + dx[d] * k;
			int ny = y + dy[d] * k;
			if (0 <= nx && nx < M && 0 <= ny && ny < N && w[n + 1] == input[ny][nx])
			{
				ret += dfs(ny, nx, n + 1);
			}
		}
	}

	return ret;
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	memset(cache, -1, sizeof(cache));

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
		cin >> input[i];
	cin >> w;

	int ans = 0;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (input[y][x] == w[0])
			{
				ans += dfs(y, x, 0);
			}
		}
	}

	cout << ans;

	return 0;
}