#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

#define MAX_N 256
#define INF 2000000000

int cache[MAX_N + 1][MAX_N + 1];
int N;
int input[MAX_N + 1];

int solve(int s, int e)
{
	int &ret = cache[s][e];

	if (ret != -1)
		return ret;

	if (s == e)
		return ret = 0;


	ret = INF;

	for (int i = s; i < e; i++)
	{
		ret = min(ret, solve(s, i) + solve(i + 1, e) + abs(*min_element(input + s, input + i + 1) - *min_element(input + i + 1, input + e + 1)));
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
			cin >> input[i];
		}

		cout << solve(0, N - 1) << endl;
	}

	return 0;
}