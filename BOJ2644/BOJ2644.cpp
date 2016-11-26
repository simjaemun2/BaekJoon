#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

#define MAX_N 100

int N,M;
int A, B;
int parent[MAX_N + 1];
int ans = 1000;


void lca(int a, int b, int cnt)
{
	if (a == b)
	{
		if (ans > cnt)
			ans = cnt;
	}

	if (cnt < ans)
	{
		if (parent[a] > 0)
			lca(parent[a], b, cnt + 1);
		if (parent[b] > 0)
			lca(a, parent[b], cnt + 1);
	}
}

int main(int argc, char** argv)
{

	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	cin >> N;
	
	cin >> A >> B >> M;

	int c, d;

	for (int i = 0; i < M; i++)
	{
		cin >> c >> d;
		parent[d] = c;
	}

	lca(A, B, 0);

	cout << (ans == 1000 ? -1 : ans);

	return 0;
}