#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <memory.h>

using namespace std;

#define MAX_N 1000
#define INF 999999999
int N;
int input[MAX_N];
int cache[MAX_N];

int solve()
{
	cache[0] = 0;

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 1; j <= input[i] && i+j < N; j++)
		{
			if (cache[i + j] > cache[i] + 1)
				cache[i + j] = cache[i] + 1;
		}
	}

	return cache[N-1] == INF ? -1 : cache[N-1];
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
			cin >> input[i];
			cache[i] = INF;
		}

		cout << solve() << endl;
	}

	return 0;
}