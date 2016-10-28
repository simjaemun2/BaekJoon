#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string>

using namespace std;

#define MAX_N 50
#define INF 2000000000
#define MOD

int N,K;
int cahe[MAX_N + 1][MAX_N + 1];

//open = 1, close = -1

int dp(int n, int pattern)
{
	if (n == 0)
		return 1;
	int ret = 0;

	if (pattern != 1)
	{
		ret += dp(n - 1, pattern - 1);
	}

	ret += dp(n - 1, pattern + 1);
}

string solve(int n, int skip)
{


	int ret = 0;

	return "";
}

int main(int argc, char** argv)
{
	int tc, T;
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	cin >> T;
	for (tc = 0; tc < T; tc++)
	{
		cin >> N >> K;

		

		if ((1 << N) < K)
		{
			cout << -1;
			continue;
		}

		cout << solve() << endl;
	}

	return 0;
}