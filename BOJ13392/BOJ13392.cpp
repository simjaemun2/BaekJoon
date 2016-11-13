#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

#define MAX_N 10000
#define INF 2000000000
#define MOD 10

int N;

int mod10(int n)
{
	if (n >= 0)
		return n % 10;
	if (-n % 10 == 0)
		return 0;
	return MOD - (-n%MOD);
}


int solve()
{
	int ret = 0;

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
	for (tc = 0; tc < T; tc++)
	{
		cin >> N;


		for (int i = 0; i<N; i++)
		{

		}

		cout << solve() << endl;
	}

	return 0;
}