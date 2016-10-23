#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

#define MAX_N 100
#define INF 2000000000
#define MOD

int N;
long long int cache[MAX_N + 1] = {0,1,1,1,2,2,3,4,5,7,9,};

long long int solve(int n)
{
	long long int &ret = cache[n];

	if (ret != 0)
		return ret;

	return ret = solve(n-1) + solve(n-5);
}

int main(int argc, char** argv)
{
	int tc, T;
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	cin >> T;
	for (tc = 0; tc < T; tc++)
	{
		cin >> N;

		cout << solve(N) << endl;
	}

	return 0;
}