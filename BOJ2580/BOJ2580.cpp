#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_N 9

int input[MAX_N][MAX_N];
vector<int> vx;
vector<int> vy;

bool isSolution = false;

void dfs(int n)
{
	if (isSolution)
		return;

	if (n == vy.size())
	{
		isSolution = true;
		return;
	}

	int cy = vy[n];
	int cx = vx[n];

	for (int i = 1; i <= MAX_N && !isSolution; i++)
	{
		int y, x, j;

		for (y = 0; y < MAX_N; y++)
		{
			if (input[y][cx] == i)
				break;
		}

		if (y != MAX_N)
			continue;

		for (x = 0; x < MAX_N; x++)
		{
			if (input[cy][x] == i)
				break;
		}

		if (x != MAX_N)
			continue;

		for (j = 0; j<9; j++)
		{
			if (input[cy / 3 * 3 + j / 3][cx / 3 * 3 + j % 3] == i)
				break;
		}

		if (j != MAX_N)
			continue;

		input[cy][cx] = i;
		dfs(n + 1);
	}

	if(!isSolution)
		input[cy][cx] = 0;
}

int main(int argc, char** argv)
{

	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	for (int i = 0; i < MAX_N; i++)
	{
		for (int j = 0; j < MAX_N; j++)
		{
			cin >> input[i][j];
			if (input[i][j] == 0)
			{
				vy.push_back(i);
				vx.push_back(j);
			}
		}
	}

	dfs(0);

	for (int i = 0; i < MAX_N; i++)
	{
		for (int j = 0; j < MAX_N; j++)
		{
			cout << input[i][j] << " ";

		}
		cout << endl;
	}

	return 0;
}