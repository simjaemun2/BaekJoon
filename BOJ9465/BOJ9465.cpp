#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 100000

int N;

int cache[2][MAX_N+1];
int sticker[2][MAX_N+1];

int dp()
{
	cache[0][1] = sticker[0][1];
	cache[0][2] = sticker[0][2] + sticker[1][1];

	cache[1][1] = sticker[1][1];
	cache[1][2] = sticker[1][2] + sticker[0][1];

	for (int i = 3; i <= N; i++)
	{
		cache[0][i] = sticker[0][i];
		cache[0][i] += max(cache[1][i - 1], cache[1][i - 2]);

		cache[1][i] = sticker[1][i];
		cache[1][i] += max(cache[0][i - 1], cache[0][i - 2]);
	}

	if (cache[0][N] < cache[1][N])
		return cache[1][N];

	return cache[0][N];
}

int main(int argc, char** argv)
{
	int tc, T;
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	cin >> T;
	for (tc = 0; tc < T; tc++)
	{
		cin >> N;

		for (int i = 0; i<2; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cin >> sticker[i][j];
			}
		}

		cout << dp() << endl;
	}

	return 0;
}