#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int V,E;
int A, B;

#define MAX_V 20000

vector<int> v[MAX_V+1];
int colors[MAX_V + 1];
queue<int> q;
int main(int argc, char** argv)
{
	int tc, T;
	
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	scanf("%d", &T);
	for (tc = 0; tc < T; tc++)
	{
		scanf("%d %d", &V, &E);

		for (int i = 1; i <= V; i++)
		{
			v[i].clear();
			colors[i] = 0;
		}

		for (int i = 0; i < E; i++)
		{
			scanf("%d %d", &A, &B);

			v[A].push_back(B);
			v[B].push_back(A);
		}

		bool isBipartite = true;

		for (int i = 1; i <= V && isBipartite; i++)
		{
			if (colors[i] == 0)
			{
				q = queue<int>();
				q.push(i);
				colors[i] = 1;

				while (!q.empty() && isBipartite)
				{
					int index = q.front();
					q.pop();
					int color = colors[index];

					for (int i = 0; i < v[index].size(); i++)
					{
						if (colors[v[index][i]] == color)
						{
							isBipartite = false;
							break;
						}
						else if (colors[v[index][i]] == 0)
						{
							colors[v[index][i]] = -color;
							q.push(v[index][i]);
						}
					}
				}
			}
		}

		if (isBipartite)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}

	return 0;
}