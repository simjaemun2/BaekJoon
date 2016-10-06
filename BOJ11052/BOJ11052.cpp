#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>

using namespace std;

#define MAX_N 1000
#define INF 100000000

int N;
int cache[MAX_N + 1];
int input[MAX_N + 1];

int solve(int n)
{
	int& ret = cache[n];

	if (ret != -1)
		return ret;

	ret = 0;

	for (int i = 0; i <= n; i++)
	{
		int t = solve(n - i);

		if (ret < t + input[i])
			ret = t + input[i];
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

		for (int i = 1; i<=N; i++)
		{
			cin >> input[i];
			cache[i] = -1;
		}

		cout << solve(N) << endl;
	}

	return 0;
}