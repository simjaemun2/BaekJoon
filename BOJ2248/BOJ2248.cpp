#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define MAX_N 32

typedef long long int LL;

int N,L;
LL I;

int bino[MAX_N + 2][MAX_N + 2];

void calcBino()
{
	bino[0][0] = 1;
	for (int i = 0; i < N; i++)
	{
		bino[i][0] = bino[i][i] = 1;

		for (int j = 1; j <= i; j++)
			bino[i][j] = bino[i - 1][j - 1] + bino[i - 1][j];
	}
}


string kth(int n, int m, LL skip)
{
	if (n == 0) return "";

	if (m == 0) return string(n,'0');

	int binoSum = 0;

	for (int i = 0; i <= m; i++)
		binoSum += bino[n - 1][i];

	if (binoSum >= skip)
		return "0" + kth(n - 1, m, skip);
	return "1" + kth(n - 1, m - 1, skip - binoSum);
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
		scanf("%d %d %lld", &N, &L, &I);
		//cin >> N >> L >> I;
		calcBino();
		printf("%s\n", kth(N, L, I).c_str());
		//cout << kth(N-1,L,I) << endl;
	}

	return 0;
}