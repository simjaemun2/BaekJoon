#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 100

int N, M,H;
int dx[6] = { -1,1,0,0 ,0,0};
int dy[6] = { 0,0,-1,1 ,0,0};
int dz[6] = { 0,0,0,0,-1,1 };

int input[MAX_N][MAX_N][MAX_N];

struct Node
{
	int y, x,z;

	Node(int _y, int _x,int _z)
	{
		y = _y;
		x = _x;
		z = _z;
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

	cin >> M >> N >> H;
	
	for (int k = 0; k < H; k++)
	{
		for (int i = 0; i<N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> input[k][i][j];
				if (input[k][i][j] == 1)
					oq.push_back(Node(i, j,k));
				else if (input[k][i][j] == 0)
					cnt++;
			}
		}
	}

	int color = 1;

	while (true)
	{
		if (cnt == 0)
			break;
		color++;

		for (int i = 0; i<oq.size(); i++)
		{
			int y = oq[i].y;
			int x = oq[i].x;
			int z = oq[i].z;
			for (int i = 0; i < 6; i++)
			{
				int nextY = y + dy[i];
				int nextX = x + dx[i];
				int nextZ = z + dz[i];

				if (0 <= nextZ && nextZ< H && 0 <= nextX && nextX < M && 0 <= nextY && nextY < N && input[nextZ][nextY][nextX] == 0)
				{
					input[nextZ][nextY][nextX] = color;
					cnt--;
					nq.push_back(Node(nextY, nextX,nextZ));
				}
			}
		}

		if (cnt > 0 && nq.size() == 0)
		{
			color = 0;
			break;
		}

		oq.clear();
		oq.swap(nq);
		
	}

	cout << color - 1;

	return 0;
}