#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

#define MAX_N 100000

int N, A, B, V;

typedef pair<int, int> PAIR;
vector<vector<PAIR > > input;
bool v1[MAX_N + 1];
bool v2[MAX_N + 1];

PAIR longest(int v, bool* visited)
{
	visited[v] = true;

	PAIR ret = make_pair(0, 0);

	for (int i = 0; i < input[v].size(); i++)
	{
		if (!visited[input[v][i].first])
		{
			PAIR p = longest(input[v][i].first, visited);

			if (ret.second < input[v][i].second + p.second)
			{
				ret.second = input[v][i].second + p.second;
				ret.first = p.first;
			}
		}
	}

	if (ret.first == 0)
		return make_pair(v, 0);
	return ret;
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	scanf("%d", &N);

	input = vector<vector<PAIR > >(N + 1);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &V);

		while (true)
		{
			scanf("%d", &A);

			if (A == -1)
				break;

			scanf("%d", &B);

			input[V].push_back(make_pair(A, B));
		}

	}

	PAIR p1 = longest(1, v1);
	PAIR p2 = longest(p1.first, v2);
	printf("%d", p2.second);

	return 0;
}