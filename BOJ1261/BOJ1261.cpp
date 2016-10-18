#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>


using namespace std;

#define MAX_NM 100
#define INF 999999999

int N,M;

int dy[4] = { 0,0,-1,1 };
int dx[4] = { -1,1,0,0 };

char input[MAX_NM][MAX_NM+1];
int cache[MAX_NM][MAX_NM];
int visited[MAX_NM][MAX_NM];

int solve(int y, int x)
{
	if (y == N - 1 && x == M - 1)
		return 0;

	int &ret = cache[y][x];

	if (ret != -1)
		return ret;
	
	int cur = input[y][x] - '0';

	ret = INF;

	priority_queue<pair<int, int> > q;

	for (int i = 0; i < 4; i++)
	{
		int nextY = y + dy[i];
		int nextX = x + dx[i];

		if (0 <= nextY && nextY < N && 0 <= nextX && nextX < M && !visited[nextY][nextX])
		{
			q.push(make_pair(-input[nextY][nextX], i));
		}
	}

	while (!q.empty())
	{
		pair<int, int> p = q.top();
		q.pop();

		int i = std::get<1>(p);

		int nextY = y + dy[i];
		int nextX = x + dx[i];

		visited[nextY][nextX] = true;
		ret = min(ret, solve(nextY, nextX) + cur);
		visited[nextY][nextX] = false;
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
		cin >> M >>N;

		for (int i = 0; i<N; i++)
		{
			cin >> input[i];
			for (int j = 0; j < M; j++)
			{
				cache[i][j] = -1;
			}
		}

		visited[0][0] = 1;
		
		cout << solve(0,0) << endl;
	}

	return 0;
}