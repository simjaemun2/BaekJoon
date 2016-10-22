#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <memory.h>

using namespace std;

#define MAX_N 20
#define MAX_M 10000
#define INF 2000000000
#define MOD

int N,M;

int input[MAX_N + 1];
int cache[MAX_M + 1];

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

	cin >> T;
	for (tc = 0; tc < T; tc++)
	{
		cin >> N;

		for (int i = 0; i < N; i++)
		{
			cin >> input[i];
		}

		cin >> M;

		memset(cache, 0, sizeof(cache));

		cache[0] = 1;

		for (int item = 0; item < N; item++)
		{
			for (int cost = input[item]; cost <= M; cost++)
			{
				cache[cost] += cache[cost - input[item]];
			}
		}

		cout << cache[M] << endl;
	}

	return 0;
}