#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 300

struct Node {
	int y, x,c;

	Node(int _y, int _x, int _c)
	{
		y = _y;
		x = _x;
		c = _c;
	}
};

int N,M;
int input[MAX_N][MAX_N];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int ng;

bool visited[MAX_N][MAX_N];

void dfs(int y, int x)
{
	visited[y][x] = true;
	ng++;

	for (int i = 0; i < 4; i++)
	{
		int nextY = y + dy[i];
		int nextX = x + dx[i];

		if (input[nextY][nextX] && !visited[nextY][nextX])
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

	cin >> N >> M;

	vector<Node > ov;
	vector<Node > nv;

	for (int i = 0; i<N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> input[i][j];
			
			if (input[i][j] > 0)
			{
				ov.push_back(Node(i, j, input[i][j]));
			}
		}
	}

	int cnt = 0;

	while (ov.size() > 0)
	{
		ng = 0;
		dfs(ov[0].y, ov[0].x);

		if (ng < ov.size())
		{
			break;
		}

		cnt++;

		for (int i = 0; i < ov.size(); i++)
		{
			for (int d = 0; d < 4; d++)
			{
				int nextY = ov[i].y + dy[d];
				int nextX = ov[i].x + dx[d];

				if (!input[nextY][nextX])
				{
					ov[i].c--;
				}
			}
		}

		for (int i = 0; i < ov.size(); i++)
		{
			visited[ov[i].y][ov[i].x] = false;

			if (ov[i].c <= 0)
			{
				input[ov[i].y][ov[i].x] = 0;
			}
			else
			{
				nv.push_back(ov[i]);
				input[ov[i].y][ov[i].x] = ov[i].c;
			}
		}

		ov.clear();
		ov.swap(nv);
	}

	cout << (ov.size() > 0 ? cnt : 0);

	return 0;
}