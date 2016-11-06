#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_NM 1000


int N,M;
char input[MAX_NM + 1][MAX_NM + 1];
int cache[MAX_NM + 1][MAX_NM + 1];



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


		for (int i = 0; i<N; i++)
		{
			cin >> input[i];
		}

		int len = 0;

		for (int i = 0; i < N; i++)
		{
			cache[i][0] = input[i][0] - '0';

			len = max(len, cache[i][0]);
		}

		for (int i = 0; i < M; i++)
		{
			cache[0][i] = input[0][i] - '0';
			len = max(len, cache[0][i]);
		}

		

		for (int i = 1; i < N; i++)
		{
			for (int j = 1; j < M; j++)
			{
				if (input[i][j] == '1')
				{
					cache[i][j] = input[i][j] - '0' + min(min(cache[i - 1][j], cache[i][j - 1]), cache[i - 1][j - 1]);
				}
				len = max(len, cache[i][j]);
			}
		}

		cout << len*len;
	}

	return 0;
}