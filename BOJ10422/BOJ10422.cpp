#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

#define MAX_N 5000
#define MOD 1000000007

int N;
long long int cache[MAX_N/2+1];

int main(int argc, char** argv)
{
	int tc, T;
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	cache[0] = 1;

	for (int i = 1; i <= MAX_N / 2 + 1;-i++)
	{
		for (int j = 0; j < i; j++)
		{
			cache[i] += cache[j] * cache[i - 1 - j];
			cache[i] %= MOD;
		}
	}

	cin >> T;

	for (tc = 0; tc < T; tc++)
	{
		cin >> N;
	
		if (N % 2 == 1)
			cout << 0 << endl;
		else
			cout << cache[N/2] << endl;
		
	}

	return 0;
}