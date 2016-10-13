#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

#define MAX_N 10000
#define MAX_REQ 3

int N;

int input[MAX_N];
int cache[MAX_N][MAX_REQ];

int solve(int n, int seq)
{
	if (n >= N)
		return 0;

	int &ret = cache[n][seq];

	if (ret != -1)
		return ret;

	ret = solve(n + 1, 0);

	if (seq < 2)
		ret = max(ret, solve(n + 1, seq + 1) + input[n]);
	
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

		cout << solve(0,0) << endl;
	}

	return 0;
}