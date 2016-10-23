#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

#define MAX_T 1000
#define MAX_W 30
#define INF 2000000000
#define MOD

int T,W;
int cache[MAX_T+1][MAX_W+1][3];
int input[MAX_T];

int solve(int t, int w, int p)
{
	if (t == T+1)
		return 0;

	int &ret = cache[t][w][p];

	if (ret != -1)
		return ret;
	
	int cur = input[t] == p ? 1 : 0;

	ret = cur + solve(t + 1, w, p);

	if (w > 0)
	{
		int nextP = p == 1 ? 2 : 1;
		ret = max(ret, cur + solve(t + 1, w - 1, nextP));
	}
	
	return ret;
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif


	cin >> T >> W;

	memset(cache, -1, sizeof(cache));

	for (int i = 1; i<=T; i++)
	{
		cin >> input[i];
	}

	int ans = solve(1, W, 1);

	cout << max(ans, solve(1,W-1,2)) << endl;
	

	return 0;
}