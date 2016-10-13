#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_MN 1000

int N,M;

int map[MAX_MN][MAX_MN];

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
		cin >> N >> M;

		for (int i = 0; i<N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> map[i][j];
			}
		}

		for (int i = 1; i < N; i++)
		{
			map[i][0] += map[i - 1][0];
		}

		for (int i = 1; i < M; i++)
		{
			map[0][i] += map[0][i - 1];
		}

		for (int i = 1; i < N; i++)
		{
			for (int j = 1; j < M; j++)
			{
				map[i][j] += max(max(map[i - 1][j], map[i][j - 1]), map[i - 1][j - 1]);
			}
		}

		cout << map[N-1][M-1] << endl;
	}

	return 0;
}