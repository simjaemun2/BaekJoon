#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 1000
#define MOD 10007

int N, K;
int cache[MAX_N + 1][MAX_N + 1];

int solve()
{
	if (N - K < K)
		K = N - K;
	
	cache[1][0] = cache[1][1] = 1;

	for (int i = 2; i <= N; i++)
	{
		cache[i][0] = cache[i][i] = 1;
		
		for (int j = 1; j <= min(i, K); j++)
		{
			cache[i][j] = (cache[i - 1][j - 1] + cache[i - 1][j])%MOD;
		}
	}

	return cache[N][K];
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
		cin >> N >> K;

		cout << solve() << endl;
	}

	return 0;
}