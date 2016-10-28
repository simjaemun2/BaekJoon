#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

#define MAX_N 500
#define INF 2111111111
#define MOD

int N;
int input[MAX_N][2];

int cache[MAX_N][MAX_N];

int solve()
{
	int ret = 0;

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


		for (int i = 0; i<N; i++)
		{
			cin >> input[i][0] >> input[i][1];
		}

		for (int i = N-1; i >= 0; i--)
		{
			for (int j = i + 1; j < N; j++)
			{
				cache[i][j] = std::numeric_limits<int>::max();

				for (int k = i; k < j; k++)
				{
					cache[i][j] = min(cache[i][j], cache[i][k] + cache[k + 1][j] + input[i][0] * input[k][1] * input[j][1]);
				}
			}
		}

		cout << cache[0][N - 1];
	}

	return 0;
}