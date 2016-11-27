#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAX_N 1000000


int N, M;
int input[MAX_N];

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
			scanf("%d", &input[i]);
		}

		sort(input, input + N);

		scanf("%d", &M);

		int a;
		int l, r, m;

		for (int i = 0; i < M; i++)
		{
			scanf("%d", &a);
			l = 0, r = N;

			while (l<r)
			{
				m = l + (r - l) / 2;

				if (input[m] < a)
					l = m + 1;
				else
					r = m;
			}

			printf("%d\n", (l < N && input[l] == a ? 1 : 0));
		}

	}

	return 0;
}