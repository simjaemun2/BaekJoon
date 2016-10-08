#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>

using namespace std;

#define MAX_N 1000
#define LEN 10
#define MOD 10007

int N;
int cache[MAX_N + 1][LEN];


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

		for (int i = 0; i < LEN; i++)
		{
			cache[1][i] = 1;
		}

		for (int i = 2; i <= N; i++)
		{
			for (int j = 0; j < LEN; j++)
			{
				for (int k = j; k < LEN; k++)
				{
					cache[i][j] = (cache[i][j] + cache[i - 1][k])%MOD;
				}
			}
		}
		
		int ans = 0;

		for (int i = 0; i < LEN; i++)
		{
			ans = (ans + cache[N][i]) % MOD;
		}

		cout << ans;
	}

	return 0;
}