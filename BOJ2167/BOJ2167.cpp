#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

#define MAX_NM 300

int N, M, K;

int input[MAX_NM + 1][MAX_NM + 1];
int cache[MAX_NM+1][MAX_NM+1];

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


		for (int i = 1; i<=N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				cin >> input[i][j];
			}
		}

		cache[1][1] = input[1][1];

		for (int i = 2; i <= N; i++)
		{
			cache[i][1] += cache[i - 1][1] + input[i][1];
		}

		for (int i = 2; i <= M; i++)
		{
			cache[1][i] += cache[1][i - 1] + input[1][i];
		}

		for (int i = 2; i <= N; i++)
		{
			for (int j = 2; j <= M; j++)
			{
				cache[i][j] = cache[i - 1][j] + cache[i][j - 1] - cache[i - 1][j - 1] + input[i][j];
			}
		}

		cin >> K;

		for (int i = 0; i < K; i++)
		{
			int a, b, c, d;
			cin >> a >> b >> c >> d;

			cout << cache[c][d] - cache[a-1][d] - cache[c][b-1] + cache[a-1][b-1] << endl;
		}
	}

	return 0;
}