#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

#define MAX_N 1000000
#define MOD 1000000000

int N;
int cache[MAX_N + 1];

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
		//memset(cache, 1, sizeof(cache));

		cache[0] = 1;

		for (int i = 0; (1 << i) <= N; i++)
		{
			for (int j = (1 << i); j <= N; j++)
			{
				cache[j] += cache[j-(1 << i)];
				cache[j] %= MOD;
			}
		}
		
		cout << cache[N];
	}

	return 0;
}