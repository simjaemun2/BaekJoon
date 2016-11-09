#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

#define MAX_N 1000
#define INF 2000000000
#define MOD

int N;
char input[MAX_N + 1];
int cache[MAX_N + 1];
char table[120];


int solve(int n)
{
	if (n == N-1)
		return 0;

	int &ret = cache[n];

	if (ret != -1)
		return ret;

	ret = INF;
	
	char next = table[input[n]];
	
	for (int i = n + 1; i < N; i++)
	{
		if (input[i] == next)
			ret = min(ret, (i - n)*(i - n) + solve(i));
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

	//in >> T;
	T = 1;

	memset(cache, -1, sizeof(cache));

	table['B'] = 'O';
	table['O'] = 'J';
	table['J'] = 'B';

	for (tc = 0; tc < T; tc++)
	{
		cin >> N >> input;

		cout << (solve(0) == INF ? -1 : solve(0)) << endl;
	}

	return 0;
}