#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

#define MAX_N 100
#define MAX_M 1000
#define INF 20000000

int N, S, M;
int cache[MAX_N + 1][MAX_M + 1];
int input[MAX_N + 1];

int solve(int n ,int v)
{
	if (n == N)
	{
		return v;
	}

	int &ret = cache[n][v];

	if (ret != -1)
		return ret;

	ret = -INF;

	if (v - input[n] >= 0)
		ret = max(ret, solve(n+1, v - input[n]));

	if (v + input[n] <= M)
		ret = max(ret, solve(n+1, v + input[n]));

	return ret;
}

int main(int argc, char** argv)
{

	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	memset(cache, -1, sizeof(cache));

	cin >> N >> S >> M;

	for (int i = 0; i<N; i++)
	{
		cin >> input[i];
	}

	cout << (solve(0, S) <= -INF ? -1 : solve(0,S));



	return 0;
}