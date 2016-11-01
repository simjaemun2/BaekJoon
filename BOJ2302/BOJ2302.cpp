#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

#define MAX_N 40

int N,M;
bool input[MAX_N + 2];
int cache[MAX_N + 2];

int fibo(int n)
{
	int &ret = cache[n];
	if (ret != -1)
		return ret;

	if (n == 1 || n == 2)
		return ret = 1;
	return ret = fibo(n - 1) + fibo(n - 2);
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
		cin >> N >> M;

		memset(cache, -1, sizeof(cache));

		for (int i = 0; i < M; i++)
		{
			int a;
			cin >> a;
			input[a] = true;
		}

		int sum = 1;
		int cnt = 0;
		input[N + 1] = true;


		for (int i = 1; i <= N+1; i++)
		{
			if (input[i])
			{
				sum *= fibo(cnt + 1);
				cnt = 0;
			}
			else
			{
				cnt++;
			}
		}


		cout << sum << endl;
	}

	return 0;
}