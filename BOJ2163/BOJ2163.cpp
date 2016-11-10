#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

#define MAX_NM 300

int N , M;
int cache[MAX_NM + 1][MAX_NM + 1];


int solve(int n, int m)
{
	if (n == 1 && m == 1)
		return 0;

	int &ret = cache[n][m];

	if (ret != -1)
		return ret;

	if (n < m)
		return ret = solve(m, n);

	return ret = 1 + solve(n-n/2,m)+ solve(n / 2, m);
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
		cin >> N >> M;

		memset(cache, -1, sizeof(cache));

		cout << solve(N,M) << endl;
	}

	return 0;
}