#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

#define MAX_N 100
#define MAX_K 10000
#define INF 999999999

int N,K;

int input[MAX_N];
int cache[MAX_K + 1];


int solve()
{
	cache[0] = 0;

	for (int i = 0; i < N; i++)
	{
		int curCoin = input[i];

		for (int j = input[i]; j <= K; j++)
		{
			if (cache[j - curCoin] + 1 < cache[j])
				cache[j] = cache[j - curCoin]+1;
		}
	}

	return cache[K] == INF ? -1 : cache[K];
}

int main(int argc, char** argv)
{
	int tc, T;
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	//in >> T;
	T = 1;
	for (tc = 0; tc < T; tc++)
	{
		cin >> N >> K;

		for (int i = 1; i <= K; i++)
		{
			cache[i] = INF;
		}

		for (int i = 0; i<N; i++)
		{
			cin >> input[i];
		}

		cout << solve() << endl;
	}

	return 0;
}