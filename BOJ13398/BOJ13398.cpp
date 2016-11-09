#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

#define MAX_N 100000

int N;
int cache[2][MAX_N];

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
		int ans = -100000;

		for (int i = 2; i < N + 2; i++)
		{
			int a;
			cin >> a;

			cache[0][i] = max(cache[0][i - 1] + a, a);
			cache[1][i] = max(cache[0][i - 2] + a, cache[1][i-1]+a);

			ans = max(ans, max(cache[0][i], cache[1][i]));
		}

		cout << ans;
	}

	return 0;
}