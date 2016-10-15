#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>

using namespace std;

#define MAX_N 1000
#define INF 99999999

int N;
int input[MAX_N + 1];
int cache[MAX_N + 1];

int solve()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			if (input[i] < input[j] && cache[i] + 1 > cache[j])
				cache[j] = cache[i] + 1;
		}
	}

	int ret = 0;

	for (int i = 1; i <= N; i++)
	{
		if (cache[i] > ret)
			ret = cache[i];
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
		}

		cout << solve() << endl;
	}

	return 0;
}