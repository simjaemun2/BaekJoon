#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_T 10000
#define MAX_K 100

int T,K;
int cache[MAX_K + 2][MAX_T + 2];

int main(int argc, char** argv)
{
	int T;
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	cin >> T >> K;

	vector<pair<int, int> > input(K);

	for (int i = 0; i < K; i++)
	{
		cin >> input[i].first >> input[i].second;
	}

	sort(input.begin(), input.end());

	for (int i = 0; i < K; i++)
	{
		cache[i][0] = 1;

		int price = input[i].first;
		int cnt = input[i].second;

		for(int j=1; j<=cnt; j++)
		{
			for (int k = price * j; k <= T; k++)
			{
				cache[i + 1][k] += cache[i][k - price * j];
			}
		}

		for (int j = 1; j <= T; j++)
		{
			cache[i + 1][j] += cache[i][j];
		}
	}

	cout << cache[K][T];


	return 0;
}