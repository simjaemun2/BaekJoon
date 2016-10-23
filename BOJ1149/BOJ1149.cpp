#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

#define MAX_N 1000
#define INF 2000000000
#define MOD

int N;
int input[MAX_N + 1][3];
int cache[MAX_N + 1][3];

/*
0,1,2 - color
*/

int solve(int n, int color)
{
	if (n == N)
		return 0;

	int &ret = cache[n][color];

	if (ret != -1)
		return ret;
	
	ret = INF;

	for (int i = 0; i < 3; i++)
	{
		if (i != color)
		{
			ret = min(ret, input[n][i]+solve(n + 1, i));
		}
	}

	return ret;
}

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
		cin >> N;

		memset(cache, -1, sizeof(cache));

		for (int i = 0; i<N; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cin >> input[i][j];
			}
		}

		int ret = INF;

		for (int i = 0; i < 3; i++)
		{
			ret = min(ret, solve(0, i));
		}

		cout << ret << endl;
	}

	return 0;
}