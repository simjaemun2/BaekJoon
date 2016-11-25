#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_N 100

int N,M,K;
int input[MAX_N][MAX_N];

int cnt;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };


void dfs(int y, int x)
{
	input[y][x] = 1;
	cnt++;
	for (int i = 0; i < 4; i++)
	{
		int nextX = x + dx[i];
		int nextY = y + dy[i];

		if (0 <= nextX&&nextX < M && 0 <= nextY && nextY < N && input[nextY][nextX] == 0)
		{
			dfs(nextY, nextX);
		}
	}
}

int main(int argc, char** argv)
{

	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	cin >> N >> M >> K;


	for (int i = 0; i<K; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int y = y1; y < y2; y++)
		{
			for (int x = x1; x < x2; x++)
			{
				input[y][x] = 1;
			}
		}

	}

	vector<int> v;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (input[y][x] == 0)
			{
				cnt = 0;
				dfs(y, x);
				v.push_back(cnt);
			}
		}
	}

	sort(v.begin(), v.end());
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}

	return 0;
}