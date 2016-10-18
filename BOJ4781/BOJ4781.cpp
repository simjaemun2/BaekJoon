#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

#define MAX_N 5000
#define MAX_M 10000

int N,M;

int cache[MAX_M + 1];
int calorie[MAX_N];
int cost[MAX_N];

int solve(int money)
{
	if (money <= 0)
		return 0;

	int &ret = cache[money];

	if (ret != -1)
		return ret;
	ret = 0;

	for (int i = 0; i < N; i++)
	{
		if (money >= cost[i])
		{
			ret = max(ret, solve(money - cost[i]) + calorie[i]);
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

	
	while (true)
	{
		double mm;
		cin >> N >> mm;

		memset(cache, -1, sizeof(cache));

		
		M = (int)(mm * 100 + 0.5);
		
		if (N == 0 && M == 0)
			break;

		for (int i = 0; i<N; i++)
		{
			cin >> calorie[i] >> mm;
			cost[i] = (int)(mm * 100 + 0.5);
		}

		cout << solve(M) << endl;
	}

	return 0;
}