#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>

using namespace std;


#define MAX_N 1000000
int N;
int cache[MAX_N + 1];


int dp(int n)
{
	int &ret = cache[n];

	if (ret != -1)
		return ret;
	if (n % 3 == 0)
	{
		ret = 1 + dp(n / 3);
	}
	else
	{
		ret = 1 + dp(n - 1);
		
		if (n%2 == 0 && ret > 1 + dp(n / 2))
		{
			ret = 1 + dp(n / 2);
		}
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

		for (int i = 2; i<=N; i++)
		{
			cache[i] = -1;
		}

		cache[1] = 0;

		cout << dp(N);
	}

	return 0;
}