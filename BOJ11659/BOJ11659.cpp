#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>

#define MAX_N 100000

int N,M;
int a, b;
int cache[MAX_N + 1];

int main(int argc, char** argv)
{
	int tc, T;

#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	//cin >> T;
	T = 1;
	for (tc = 0; tc < T; tc++)
	{
		//cin >> N >> M;
		scanf("%d %d", &N, &M);

		for (int i = 1; i <= N; i++)
		{
			scanf("%d",&cache[i]);
			cache[i] += cache[i - 1];
		}


		for (int i = 0; i < M; i++)
		{
			scanf("%d %d", &a, &b);
			printf("%d\n", cache[b] - cache[a - 1]);
		}
	}

	return 0;
}