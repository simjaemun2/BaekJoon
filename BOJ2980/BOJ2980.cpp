#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>

using namespace std;

#define MAX_N 1000

int N, L;
int D, R, G;

int main(int argc, char** argv)
{
	int tc, T;
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r",
		stdin);
#endif

	//cin >> T;
	T = 1;
	for (tc = 0; tc < T; tc++)
	{
		int ans = 0;

		cin >> N >> L;

		int beforeD = 0;

		for (int i = 0; i < N; i++)
		{
			cin >> D >> R >> G;

			ans += D - beforeD;

			beforeD = D;

			if (ans % (R + G) <= R)
			{
				ans += R - ans % (R + G);
			}
		}

		cout << ans + L - beforeD << endl;
	}

	return 0;
}