#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define MAX_N 1000
#define MAX_M 100000
#define INF 200000000

int N,M;
vector<pair<int, int> > adj[MAX_N+1];
priority_queue<pair<int, int> > pq;

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
		cin >> N >> M;


		for (int i = 0; i<M; i++)
		{
			int source, destination, distance;
			cin >> source >> destination >> distance;

			adj[source].push_back(make_pair(destination, distance));
		}

		vector<int> dist(N+1, INF);
		
		int src, dst;
		cin >> src >> dst;

		dist[src] = 0;
		
		pq.push(make_pair(0, src));

		while (!pq.empty())
		{
			int cost = -pq.top().first;
			int here = pq.top().second;
			pq.pop();

			if (dist[here] < cost) continue;

			for (int i = 0; i < adj[here].size(); i++)
			{
				int there = adj[here][i].first;
				int nextDist = cost + adj[here][i].second;

				if (dist[there] > nextDist)
				{
					dist[there] = nextDist;
					pq.push(make_pair(-nextDist, there));
				}
			}
		}

		cout << dist[dst];
	}

	return 0;
}