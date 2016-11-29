#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 1000000
bool isNotPrime[MAX_N + 1];
int N;
vector<int> vIsPrime;

void getPrimes()
{
	isNotPrime[0] = isNotPrime[1] = true;

	for (int i = 3; i <= 1000; i += 2)
	{
		if (!isNotPrime[i])
		{
			vIsPrime.push_back(i);
			for (int j = i*i; j <= MAX_N; j += i)
			{
				isNotPrime[j] = true;
			}
		}
	}
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	getPrimes();

	while(true)
	{
		scanf("%d", &N);

		if (N == 0)
			break;
		int i = 0;

		for (; vIsPrime[i] <= N / 2; i++)
		{
			if (!isNotPrime[N - vIsPrime[i]])
			{
				printf("%d = %d + %d\n", N, vIsPrime[i], N - vIsPrime[i]);
				break;
			}
		}

		if (vIsPrime[i] > N / 2)
			printf("Goldbach's conjecture is wrong.\n");
	}

	return 0;
}