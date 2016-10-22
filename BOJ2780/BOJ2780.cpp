#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

#define MAX_N 1000
#define INF 2000000000
#define MOD 1234567

int N;

int key[10][5] = {
	{ 1,7,0,0,0 },//0
	{ 2,2,4,0,0 },//1
	{ 3,1,3,5,0 },//2
	{ 2,2,6,0,0 },//3
	{ 3,1,5,7,0 },//4
	{ 4,2,4,6,8 },//5
	{ 3,3,5,9,0 },//6
	{ 3,4,8,0,0 },//7
	{ 3,5,7,9,0 },//8
	{ 2,6,8,0,0 },//9
	
};

int cache[10][MAX_N + 1];

int solve(int index, int len)
{
	if (len == 1)
		return 1;

	int &ret = cache[index][len];

	if (ret != -1)
		return ret;
	ret = 0;

	for (int i = 1; i <= key[index][0]; i++)
	{
		ret += solve(key[index][i],len-1);
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

	cin >> T;

	memset(cache, -1, sizeof(cache));

	for (tc = 0; tc < T; tc++)
	{
		cin >> N;

		int ans = 0;

		for (int i = 0; i <= 9; i++)
		{
			ans += solve(i, N);
			ans %= MOD;
		}
			

		cout << ans << endl;
	}

	return 0;
}