#define _CRT_SECURE_NO_WARNINGS 
 
#include <iostream>
#include <memory.h>
 
using namespace std;
 
#define MAX_N 1000
#define MAX_ABSENCE 3
#define MAX_LATE 2

#define MOD 1000000

int N;
int cache[MAX_N + 1][MAX_ABSENCE + 1][MAX_LATE + 1];
 
int solve(int n, int late, int absence)
{
	if (n == N)
		return 1;

	int &ret = cache[n][late][absence];

	if (ret != -1)
		return ret;

	ret = 0;

	ret += solve(n + 1, late, 0);
	ret %= MOD;

	if (late < 1)
	{
		ret += solve(n + 1, late + 1, 0);
		ret %= MOD;
	}
		

	if (absence < 2)
	{
		ret += solve(n + 1, late, absence + 1);
		ret %= MOD;
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
		memset(cache, -1, sizeof(cache));
		cout << solve(0,0,0) << endl;
	}
 
	return 0;
}