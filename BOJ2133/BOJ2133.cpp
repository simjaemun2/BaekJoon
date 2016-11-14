#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>

using namespace std;

#define MAX_N 30

int N;

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

		int f[MAX_N + 5] = { 1,0 };
		int g[MAX_N + 5] = { 0,1 };

		for (int i = 2; i <= N; i++)
		{
			f[i] = f[i - 2] + 2 * g[i - 1];
			g[i] = f[i - 1] + g[i - 2];
		}
		
		cout << f[N];
	}

	return 0;
}