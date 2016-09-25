#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>

using namespace std;

#define MAX_N 1000
#define W 0
#define G 1
#define B 2

int ans;
int N;
int nums[MAX_N + 1];
int colors[MAX_N + 1];

void colorB(int cur)
{
	ans++;
	
	while (true)
	{
		colors[cur] = B;
		int next = nums[cur];

		if (colors[next] == B)
			break;
		else
		{
			cur = next;
		}
	}
}

void dfs(int cur)
{
	colors[cur] = G;

	int next = nums[cur];

	if (colors[next] == W)
	{
		dfs(next);
	}
	else if (colors[next] == G)
	{
		colorB(next);
	}

	colors[cur] = B;
}

int main(int argc, char** argv)
{
	int tc, T;
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r",
		stdin);
#endif

	cin >> T;
	for (tc = 0; tc < T; tc++)
	{
		cin >> N;
		ans = 0;
		for (int i = 1; i <= N; i++)
		{
			colors[i] = W;

			cin >> nums[i];

			if (nums[i] == i)
			{
				colors[i] = B;
				ans++;
			}
		}

		for (int i = 1; i <= N; i++)
		{
			if (colors[i] == W)
			{
				dfs(i);
			}
		}

		cout << ans << endl;
	}

	return 0;
}