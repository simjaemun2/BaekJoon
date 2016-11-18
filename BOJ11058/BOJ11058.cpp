#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 100

int N;
long long int cache[MAX_N+1];

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

		cache[1] = 1;
		cache[2] = 2;
		cache[3] = 3;
		cache[4] = 4;
		cache[5] = 5;

		for (int i = 2; i<=N; i++)
		{
			for (int j = 2; j+i+1 <= N; j++)
			{
				cache[j+i+1] = max(cache[j + i + 1], cache[i] * j);
			}
		}

		cout << cache[N] << endl;
	}

	return 0;
}