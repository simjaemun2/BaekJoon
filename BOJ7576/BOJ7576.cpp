#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 1000

int N,M;
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

int main(int argc, char** argv)
{

	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	vector<Node> oq;
	vector<Node> nq;

	int cnt = 0;

	cin >> M >> N;

	for (int i = 0; i<N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> input[i][j];
			if (input[i][j] == 1)
				oq.push_back(Node(i, j));
			else if (input[i][j] == 0)
				cnt++;
		}
	}

	int color = 1;

	while (true)
	{
		if (cnt == 0)
			break;
		color++;

		for(int i=0; i<oq.size(); i++)
		{
			int y = oq[i].y;
			int x = oq[i].x;
		
			for (int i = 0; i < 4; i++)
			{
				int nextY = y + dy[i];
				int nextX = x + dx[i];

				if (0 <= nextX && nextX < M && 0 <= nextY && nextY < N && input[nextY][nextX] == 0)
				{
					input[nextY][nextX] = color;
					cnt--;
					nq.push_back(Node(nextY, nextX));
				}
			}
		}
		
		if (cnt > 0 && nq.size() == 0)
		{
			color = 0;
			break;
		}

		oq.assign(nq.begin(), nq.end());
		nq.clear();
	}

	cout << color - 1;

	return 0;
}