#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>

using namespace std;

#define MAX_N 1000000
#define MOD 15746

int cache[MAX_N + 1];
int N;


int solve(int n)
{
	int &ret = cache[n];

	if (cache[n] != -1)
		return cache[n];
	return ret = (solve(n-1) + solve(n-2))%MOD;
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

		for (int i = 1; i <= N; i++)
		{
			cache[i] = -1;
		}

		cache[1] = 1;
		cache[2] = 2;

		cout << solve(N) << endl;
	}

	return 0;
}