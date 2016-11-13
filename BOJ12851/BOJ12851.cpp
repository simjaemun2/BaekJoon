#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define MAX_N 100000
#define INF 200000000

int N, K;

struct Node {
	int position, cost;

	Node(int p, int c)
	{
		position = p;
		cost = c;
	}
};

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
		cin >> N >> K;

		queue<Node> q;
		Node n(N, 0);
		q.push(n);

		vector<int > isVisited(MAX_N+1, INF);

		int minCost = 0;
		int minCostCnt = 0;

		while (!q.empty())
		{
			Node node = q.front();

			if (isVisited[node.position] >= node.cost)
			{
				isVisited[node.position] = node.cost;

				if (minCost != 0 && node.cost > minCost)
					break;

				if (node.position == K)
				{
					minCost = node.cost;
					minCostCnt++;
				}

				if (minCost == 0)
				{
					if (node.position - 1 >= 0)
					{
						q.push(Node(node.position - 1, node.cost + 1));
					}

					if (node.position + 1 <= MAX_N)
					{
						q.push(Node(node.position + 1, node.cost + 1));
					}

					if (node.position * 2 <= MAX_N)
					{
						q.push(Node(node.position * 2, node.cost + 1));
					}
				}
			}

			

			q.pop();
		}

		cout << minCost << endl;
		cout << minCostCnt << endl;
	}

	return 0;
}