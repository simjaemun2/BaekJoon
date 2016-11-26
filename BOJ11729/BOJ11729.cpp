#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>

int N;


void solve(int n, int a, int b, int c)
{
	if (n == 1)
	{
		printf("%d %d\n", a, c);
	}
	else
	{
		solve(n - 1, a, c, b);
		printf("%d %d\n", a, c);
		solve(n - 1, b, a, c);
	}
}

int main(int argc, char** argv)
{

#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif


	scanf("%d", &N);

	printf("%d\n", (1 << N) - 1);

	solve(N, 1, 2, 3);

	

	return 0;
}