#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>

using namespace std;

#define MAX_N 300000

int N;

int tt[150];
int cache[MAX_N + 1];

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
		cin >> N;
		int maxT = 1;


		while (true)
		{
			tt[maxT] = (maxT*(maxT + 1)*(2 * maxT + 1) / 6 + maxT*(maxT + 1) / 2) / 2;
			if (tt[maxT] > N)
				break;
			maxT++;
		}

		for (int i = 1; i <= N; i++)
		{
			cache[i] = i;
		}

		for (int i = 2; i < maxT; i++)
		{
			for (int j = tt[i]; j <= N; j++)
			{
				if (cache[j - tt[i]] + 1 < cache[j])
					cache[j] = cache[j - tt[i]] + 1;
			}
		}

		cout << cache[N];
	}

	return 0;
}