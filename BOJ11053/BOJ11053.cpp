#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

#define MAX_N 1000
#define INF 2000000000
#define MOD

int N;
int input[MAX_N];
int cache[MAX_N];

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

		for (int i = 0; i<N; i++)
		{
			cin >> input[i];
		}

		for (int i = 0; i < N - 1; i++)
		{
			for (int j = i + 1; j < N; j++)
			{
				if (input[i] < input[j] && cache[i] + 1 > cache[j])
				{
					cache[j] = cache[i] + 1;
				}
			}
		}

		int ans = cache[0];

		for (int i = 1; i < N; i++)
			ans = max(ans, cache[i]);

		cout << ans + 1;
	}

	return 0;
}