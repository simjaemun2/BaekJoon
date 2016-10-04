#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>

using namespace std;


#define MAX_N 100
#define MOD 1000000000
int N;
int cache[MAX_N + 1][10];


int dp(int n)
{
	cache[1][0] = 0;
	
	int sum = 0;

	for (int i = 1; i <= 9; i++)
		cache[1][i] = 1;

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j == 0)
				cache[i][0] = cache[i - 1][1];
			else if (j == 9)
				cache[i][9] = cache[i - 1][8];
			else
			{
				cache[i][j] = (cache[i - 1][j - 1] + cache[i - 1][j + 1]) % MOD;
			}
		}
	}

	for (int i = 0; i <= 9; i++)
	{
		sum += cache[N][i];
		sum %= MOD;
	}

	return sum;
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

		//cout << dp(N);
	}

	cout << (!0);

	return 0;
}