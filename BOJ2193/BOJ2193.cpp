#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>

using namespace std;


#define MAX_N 90

int N;
long long cache[MAX_N + 1];


long long dp()
{
	cache[1] = cache[2] = 1;

	for (int i = 3; i <= N; i++)
	{
		cache[i] = cache[i - 1] + cache[i - 2];
		
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

		cout << dp();
	}

	return 0;
}