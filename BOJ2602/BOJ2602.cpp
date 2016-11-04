#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string>

using namespace std;

#define MAX_N 20
#define MAX_M 100
#define INF 2000000000
#define MOD

//N : length of duru
//M : length of doldari
int N,M;
char duru[MAX_N + 2];
char doldari[2][MAX_M + 2];

long long int cache[MAX_N + 20][MAX_M + 20][2];

long long int dp(int n, int m, int turn)
{
	if (n == N)
		return 1;
	if (m == M)
		return 0;

	long long int &ret = cache[n][m+1][turn];

	if (ret != -1)
		return ret;

	ret = 0;


	for (int i = m+1; i < M; i++)
	{
		if (duru[n] == doldari[turn][i])
			ret += dp(n + 1, i, (turn+1)%2);
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
		memset(cache, -1, sizeof(cache));

		cin >> duru >> doldari[0] >> doldari[1];

		N = strlen(duru);
		M = strlen(doldari[0]);
		
		if (N > M)
		{
			cout << 0;

			return 0;
		}		

		cout << dp(0,-1,0) + dp(0, -1, 1);
	}

	return 0;
}