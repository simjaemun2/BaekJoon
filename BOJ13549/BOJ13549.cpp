#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

#define MAX_N 100000

int N, K;

class Node {
public:
	int position, cost;

	Node(int p, int c)
	{
		position = p;
		cost = c;
	}

	bool operator > (const Node &n2) const
	{
		return cost > n2.cost;
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

		vector<bool> visited(MAX_N + 1, false);

		priority_queue<Node, vector<Node >, greater<Node>> q;
		
		Node n(N, 0);
		q.push(n);

		while (true)
		{
			Node node = q.top();

			if (!visited[node.position])
			{
				visited[node.position] = true;

				if (node.position == K)
				{
					cout << node.cost;
					return 0;
				}

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
					q.push(Node(node.position * 2, node.cost));
				}
			}

			q.pop();
		}
	}

	return 0;
}