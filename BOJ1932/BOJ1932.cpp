#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 500
#define INF 2000000000
#define MOD

int N;

int cache[MAX_N + 1][MAX_N + 1];

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

		for (int i = 1; i<=N; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				int a;
				cin >> a;
				cache[i][j] = a + cache[i - 1][j];
				if(j>1)
					cache[i][j] = max(cache[i][j],a + cache[i - 1][j-1]);
			}
		}

		int ret = -1;

		for (int i = 1; i <= N; i++)
		{
			ret = max(ret, cache[N][i]);
		}

		cout << ret;
	}

	return 0;
}