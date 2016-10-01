#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>

using namespace std;

const int MAX_LEN = 50;
const char W = 'W';
const char L = 'L';


int R, C;
char map[MAX_LEN][MAX_LEN + 1];
bool visited[MAX_LEN][MAX_LEN];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
int ans = 0;


struct Node {
	int y, x, dist;
};

Node q[MAX_LEN*MAX_LEN + 1];

void initVisited()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			visited[i][j] = false;
		}
	}
}

int main(int argc, char** argv)
{
	int tc, T;
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r",
		stdin);
#endif

	//cin >> T;
	T = 1;
	for (tc = 0; tc < T; tc++)
	{
		cin >> R >> C;

		for (int i = 0; i < R; i++)
		{
			cin >> map[i];
		}

		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (map[i][j] == L)
				{
					initVisited();
					
					visited[i][j] = true;
					int f = -1;
					int r = 0;

					q[0].y = i;
					q[0].x = j;
					q[0].dist = 0;

					while (f < r)
					{
						Node node = q[++f];
						
						if (node.dist > ans)
							ans = node.dist;

						for (int k = 0; k < 4; k++)
						{
							int nextY = node.y + dy[k];
							int nextX = node.x + dx[k];

							if (0 <= nextY && nextY <= R - 1
								&& 0 <= nextX && nextX <= C - 1
								&& !visited[nextY][nextX]
								&& map[nextY][nextX] == L)
							{
								q[++r].y = nextY;
								q[r].x = nextX;
								q[r].dist = node.dist + 1;
								visited[nextY][nextX] = true;
							}
						}
					}

				}
			}
		}

		cout << ans << endl;
	}

	return 0;
}