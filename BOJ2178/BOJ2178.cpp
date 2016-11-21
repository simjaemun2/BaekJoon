#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <queue>

using namespace std;

#define MAX_N 100

int N,M;
char input[MAX_N][MAX_N + 1];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

struct Node 
{
	int y, x,c;
	
	Node(int _y, int _x, int _c)
	{
		y = _y;
		x = _x;
		c = _c;
	}
};

int main(int argc, char** argv)
{

	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	cin >> N >> M;


	for (int i = 0; i<N; i++)
	{
		cin >> input[i];
	}

	queue<Node> q;
	q.push(Node(0, 0, 1));
	input[0][0] = 0;
	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		int c = q.front().c;
		q.pop();

		if (y == N - 1 && x == M - 1)
		{
			cout << c;
			break;
		}

		

		for (int i = 0; i < 4; i++)
		{
			int nextY = y + dy[i];
			int nextX = x + dx[i];

			if (0 <= nextX && nextX < M && 0 <= nextY && nextY < N && input[nextY][nextX] == '1')
			{
				input[nextY][nextX] = 0;
				q.push(Node(nextY, nextX, c + 1));
			}
		}

		
	}


	return 0;
}
