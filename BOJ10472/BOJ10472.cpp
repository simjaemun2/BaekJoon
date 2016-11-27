#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>

using namespace std;

#define MAX_N 3
int board[MAX_N];
int N;

int ans;

void push(int y, int x, int b[])
{
	b[y] ^= (1 << x);

	if (y - 1 >= 0)
		b[y-1] ^= (1 << x);
	if (x - 1 >= 0)
		b[y] ^= (1 << (x - 1));
	if (y + 1 < MAX_N)
		b[y + 1] ^= (1 << x);
	if (x + 1 < MAX_N)
		b[y] ^= (1 << (x + 1));
}

void dfs(int n, int cnt)
{
	if (n == MAX_N)
	{
		int tb[3] = { board[0], board[1], board[2] };
		for (int i = 0; i < MAX_N; i++)
		{
			if ((tb[0] >> i) & 1)
			{
				cnt++;
				push(1, i,tb);
			}
		}

		if (tb[0])
			return ;

		for (int i = 0; i < MAX_N; i++)
		{
			if ((tb[1] >> i) & 1)
			{
				cnt++;
				push(2, i,tb);
			}
		}

		if (tb[1] || tb[2])
			return;

		if (cnt < ans)
			ans = cnt;

		return ;
	}

	dfs(n + 1, cnt);
	push(0, n,board);
	dfs(n + 1, cnt + 1);
	push(0, n, board);
}

int main(int argc, char** argv)
{
	int tc, T;
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	cin >> T;
	for (tc = 0; tc < T; tc++)
	{
		char c;
		for (int i = 0; i < 3; i++)
		{
			board[i] = 0;
			for (int j = 0; j < 3; j++)
			{
				cin >> c;
				if (c == '*')
					board[i] |= (1<<j);
			}
		}

		ans = 10;
		dfs(0, 0);
		cout << ans << endl;
	}

	return 0;
}