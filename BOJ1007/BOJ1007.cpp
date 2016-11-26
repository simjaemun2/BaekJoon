#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>


using namespace std;

#define MAX_N 20

typedef long long int LL;

int N;
int inputX[MAX_N];
int inputY[MAX_N];

long long int ans;

void dfs(int y, int x, int plus, int minus, int n)
{
	if (plus == N / 2)
	{
		for (int i = n; i < N; i++)
		{
			y -= inputY[i];
			x -= inputX[i];
		}

		if (ans > (LL)x*x + (LL)y*y)
			ans = (LL)x*x + (LL)y*y;
		return;
	}

	if (minus == N / 2)
	{
		for (int i = n; i < N; i++)
		{
			y += inputY[i];
			x += inputX[i];
		}

		if ((LL)x*x + (LL)y*y)
			(LL)x*x + (LL)y*y;
		return;
	}

	dfs(y + inputY[n], x + inputX[n], plus + 1, minus, n + 1);
	dfs(y - inputY[n], x - inputX[n], plus, minus + 1, n + 1);
}

int main(int argc, char** argv)
{
	int tc, T;
	
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	scanf("%d", &T);
	for (tc = 0; tc < T; tc++)
	{
		scanf("%d", &N);


		for (int i = 0; i<N; i++)
		{
			scanf("%d %d", &inputX[i], &inputY[i]);
		}

		ans = 9876543212345;
		dfs(0, 0, 0, 0, 0);

		printf("%6lf\n", sqrt(ans));
	}

	return 0;
}