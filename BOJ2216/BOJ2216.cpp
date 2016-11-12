#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 3000
#define INF 2000000000

int A,B,C;
char X[MAX_N + 1];
char Y[MAX_N + 1];

int cache[MAX_N+1][MAX_N+1];


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
		cin >> A >> B >> C;
		
		cin >> X >> Y;

		int lenX = 0;
		int lenY = 0;

		for (; X[lenX]; lenX++)
		{
			cache[0][lenX+1] = cache[0][lenX] + B;
		}

		for (; Y[lenY]; lenY++)
		{
			cache[lenY+1][0] = cache[lenY][0] + B;
		}

		for (int y = 1; y <= lenY; y++)
		{
			for (int x = 1; x <= lenX; x++)
			{
				if (Y[y - 1] == X[x - 1])
				{
					cache[y][x] = A + cache[y - 1][x - 1];
				}
				else
				{
					cache[y][x] = C+ cache[y - 1][x - 1];
					cache[y][x] = max(cache[y][x], cache[y - 1][x] + B);
					cache[y][x] = max(cache[y][x], cache[y][x - 1] + B);
				}
			}
		}

		cout << cache[lenY][lenX];
	}

	return 0;
}