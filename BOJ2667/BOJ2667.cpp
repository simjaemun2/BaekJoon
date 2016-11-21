#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_N 25
#define INF 2000000000

int N;
char input[MAX_N][MAX_N + 1];
int cnt;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void dfs(int y, int x)
{
	input[y][x] = 0;
	cnt++;
	for (int i = 0; i < 4; i++)
	{
		int nextY = y + dy[i];
		int nextX = x + dx[i];

		if (0 <= nextX && nextX < N && 0 <= nextY && nextY < N && input[nextY][nextX] == '1')
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

	cin >> N;


	for (int i = 0; i<N; i++)
	{
		cin >> input[i];
	}

	vector<int> v;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (input[i][j] == '1')
			{
				cnt = 0;
				dfs(i,j);
				v.push_back(cnt);
			}
		}
	}

	sort(v.begin(), v.end());

	cout << v.size() << endl;

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}


	return 0;
}