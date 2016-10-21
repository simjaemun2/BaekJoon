#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_NM 15

int N,M,K;
int bino[MAX_NM*2 + 2][MAX_NM*2 + 2];

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
		cin >> N >> M >> K;

		for (int i = 0; i <= N + M; i++)
		{
			bino[i][0] = bino[i][i] = 1;
			for(int j = 1; j < i; j++)
			{
				bino[i][j] = bino[i - 1][j - 1] + bino[i - 1][j];
			}
		}

		if (K == 0)
			cout << bino[N+M-2][N-1];
		else
		{
			int y = (K-1)/M+1;
			int x = (K-1)%M+1;

			cout << (bino[x+y-2][x-1] * bino[N+M-x-y][N-y]);
		}
	}

	return 0;
}