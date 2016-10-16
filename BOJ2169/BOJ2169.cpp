#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_NM 1000
#define NINF -2000000000


int N,M;
int input[MAX_NM][MAX_NM];
int cache[MAX_NM][MAX_NM][3];
int visited[MAX_NM][MAX_NM];
int dy[3] = {0,0,1};
int dx[3] = {-1,1,0};


int solve(int y, int x, int d)
{
	if (y == N - 1 && x == M - 1)
		return input[y][x];

	int &ret = cache[y][x][d];
	
	if (ret != NINF)
		return ret;

	for (int i = 0; i < 3; i++)
	{
		int nextY = y + dy[i];
		int nextX = x + dx[i];

		if (nextY < N && 0 <= nextX && nextX < M && !visited[nextY][nextX])
		{
			visited[nextY][nextX] = true;
			ret = max(ret, input[y][x] + solve(nextY, nextX, i));
			visited[nextY][nextX] = false;
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
		cin >> N >> M;

		for (int i = 0; i<N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> input[i][j];
				
				for (int k = 0; k < 3; k++)
				{
					cache[i][j][k] = NINF;
				}
				
			}
		}

		visited[0][0] = true;
		cout << solve(0,0,0) << endl;
	}

	return 0;
}