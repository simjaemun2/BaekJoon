#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>

using namespace std;

#define MAX_N 100000

int N;
int cache[MAX_N + 1];

int solve()
{
	for (int i = 1; i <= N; i++)
	{
		cache[i] = cache[i - 1] + 1;
	}

	for (int i = 2; i*i <= N; i++)
	{
		for (int j = i*i; j <= N; j++)
		{
			if (cache[j - i*i] + 1 < cache[j])
				cache[j] = cache[j - i*i] + 1;
		}
	}

	return cache[N];
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

		cout << solve() << endl;
	}

	return 0;
}