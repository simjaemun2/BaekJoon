#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

#define MAX_N 500
#define INF 2000000000

int cache[MAX_N + 1][MAX_N + 1];
int N;
int input[MAX_N + 1];
int partialSum[MAX_N + 1];

int solve(int s, int e)
{
	int &ret = cache[s][e];

	if (ret != -1)
		return ret;

	if (s == e)
		return ret = 0;
	if (s + 1 == e)
		return ret = input[s] + input[e];

	
	ret = INF;

	for (int i = s; i < e; i++)
	{
		ret = min(ret, solve(s, i) + solve(i + 1, e) + partialSum[e+1]- partialSum[s]);
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

	cin >> T;
	for (tc = 0; tc < T; tc++)
	{
		cin >> N;

		memset(cache, -1, sizeof(cache));

		for (int i = 0; i<N; i++)
		{
			cin >> input[i];
			partialSum[i + 1] = partialSum[i] + input[i];
		}

		cout << solve(0,N-1) << endl;
	}

	return 0;
}