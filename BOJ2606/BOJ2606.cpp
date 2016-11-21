#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>


using namespace std;

#define MAX_N 100

int N,M;

bool visited[MAX_N + 1];
int input[MAX_N + 1][MAX_N + 1];
int ans;

void solve(int n)
{
	if (visited[n])
	{
		return;
	}

	visited[n] = true;
	ans++;


	for (int i = 1; i <= input[n][0]; i++)
	{
		solve(input[n][i]);
	}
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b;

		cin >> a >> b;

		input[a][++input[a][0]] = b;
		input[b][++input[b][0]] = a;
	}

	solve(1);

	cout << ans-1;


	return 0;
}