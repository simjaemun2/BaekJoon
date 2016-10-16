#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;


#define MAX_N 300

int N;
int cache[MAX_N+1][2];
int input[MAX_N+1];

int solve(int n, int s)
{
	if (n >= N)
		return input[N];

	int &ret = cache[n][s];

	if (ret != -1)
		return ret;

	if (n == 0)
	{
		ret = max(solve(1, 1), solve(2, 1));
	}

	if (n < N - 1)
		ret = max(ret, input[n] + solve(n + 2, 1));

	if (s == 1)
	{
		ret = max(ret,input[n] + solve(n + 1, 2));
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

		for (int i = 1; i<=N; i++)
		{
			cin >> input[i];
		}

		cout << solve(0,0) << endl;
	}

	return 0;
}