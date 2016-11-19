#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>


using namespace std;

#define MOD 987654321
#define MAX_N 5000

int N;
typedef long long int LL;
LL dp[MAX_N + 1];

int main(int argc, char** argv)
{
	
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	
	cin >> N;

	N /= 2;

	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i<=N; i++)
	{
		for (int j = 0; j <= i - 1; j++)
		{
			dp[i] += dp[j] * dp[i - 1 - j];
			dp[i] %= MOD;
		}
	}

	cout << dp[N];

	return 0;
}