#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 1000

int N;
int cache[MAX_N + 2];
int input[MAX_N + 2];


int solve()
{
	cache[1] = input[1];

	for (int i = 1; i < N; i++)
	{
		for (int j = i+1; j <= N; j++)
		{
			if (input[i] < input[j] && cache[i] + input[j] > cache[j])
			{
				cache[j] = cache[i] + input[j];
			}
		}
	}

	int ret = 0;

	for (int i = 1; i <= N; i++)
	{
		ret = max(ret, cache[i]);
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
			cache[i] = input[i];
		}

		cout << solve() << endl;
	}

	return 0;
}