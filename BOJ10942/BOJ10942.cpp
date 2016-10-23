#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

#define MAX_N 2000

int N,M,S,E;
int input[MAX_N + 1];
int cache[MAX_N + 1][MAX_N + 1];

int solve(int s, int e)
{
	if (s >= e)
		return 1;

	int& ret = cache[s][e];

	if (ret != -1)
		return ret;

	ret = 1;

	if (input[s] != input[e])
		return ret = 0;

	return ret = solve(s+1,e-1);
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
		//cin >> N;

		scanf("%d", &N);

		memset(cache, -1, sizeof(cache));

		for (int i = 1; i<=N; i++)
		{
			scanf("%d", &input[i]);
		}

		scanf("%d", &M);

		for (int i = 0; i < M; i++)
		{
			scanf("%d %d", &S,&E);
			printf("%d\n", solve(S, E));
		}
	}

	return 0;
}