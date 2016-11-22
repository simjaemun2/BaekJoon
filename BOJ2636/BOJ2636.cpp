#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX_N 100
#define INF 5

int N, M;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int input[MAX_N][MAX_N];


struct Node
{
	int y, x;

	Node(int _y, int _x)
	{
		y = _y;
		x = _x;
	}
};

queue<Node> q;

void color(int c)
{
	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		q.pop();
		input[y][x] = INF + c;
		
		for (int j = 0; j < 4; j++)
		{
			int nextY = y + dy[j];
			int nextX = x + dx[j];

			if (0 <= nextX && nextX < M && 0 <= nextY && nextY < N &&input[nextY][nextX] == 0)
			{
				input[nextY][nextX] = INF + c;
				q.push(Node(nextY, nextX));
			}
		}

	}
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	vector<Node> oq;
	vector<Node> nq;

	cin >> N >> M;

	for (int i = 0; i<N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> input[i][j];
			
			if (input[i][j] == 1)
			{
				oq.push_back(Node(i, j));
			}
		}
	}

	int cnt = 0;
	int lastCnt = 0;
	q.push(Node(0,0));
	
	while (!oq.empty())
	{
		lastCnt = oq.size();
		
		color(cnt);

		for (int i = 0; i<oq.size(); i++)
		{
			int y = oq[i].y;
			int x = oq[i].x;

			int j;

			for (j = 0; j < 4; j++)
			{
				int nextY = y + dy[j];
				int nextX = x + dx[j];

				if (input[nextY][nextX] == INF+cnt)
				{
					break;
				}
			}

			if (j == 4)
			{
				nq.push_back(Node(y, x));
			}
			else
			{
				input[y][x] = INF+cnt+1;
				q.push(Node(y, x));
			}
		}

		cnt++;

		oq.clear();
		oq.swap(nq);
	}

	cout << cnt << endl << lastCnt;

	return 0;
}