#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <memory.h>

using namespace std;

#define MAX_N 100
#define OPERAND_RANGE 20

typedef long long int LL;

int input[MAX_N + 1];

int N;

LL cache[OPERAND_RANGE+1][MAX_N + 1];

LL solve(int operand, int index)
{
	if (index == N - 1)
	{
		if (operand == input[N - 1])
			return 1L;
		return 0;
	}

	LL &ret = cache[operand][index];

	if (ret != -1)
		return ret;
	ret = 0;

	if (operand + input[index] <= 20)
		ret += solve(operand + input[index], index + 1);
	if (operand - input[index] >= 0)
		ret += solve(operand - input[index], index + 1);

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

		memset(cache, -1L, sizeof(cache));

		for (int i = 0; i<N; i++)
		{
			cin >> input[i];
		}

		cout << solve(input[0],1) << endl;
	}

	return 0;
}