#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

#define MAX_N 800
#define INF 10000000

int N,M;
int adj[MAX_N + 1][MAX_N + 1];

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
			for (int j = 1; j <= N; j++)
			{
				if (i != j)
					adj[i][j] = INF;
			}
		}


		for (int i = 0; i<M; i++)
		{
			int a, b, c;
			//in >> a >> b >> c;
			scanf("%d %d %d", &a, &b, &c);

			adj[a][b] = c;
			adj[b][a] = c;
		}
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		//cin >> t1 >> t2;

		for (int k = 1; k <= N; k++)
		{
			for (int i = 1; i <= N; i++)
			{
				for (int j = 1; j <= N; j++)
				{
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
				}
			}
		}

		int ans = adj[t1][t2] + min(adj[1][t1] + adj[t2][N], adj[1][t2] + adj[t1][N]);

		printf("%d", (ans >= INF ? -1 : ans));

		//cout << (ans >= INF ? -1 : ans);

	}

	return 0;
}