#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

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

		int sum;
		cin >> sum;

		int a;

		int ans = sum;

		for (int i = 1; i<N; i++)
		{
			cin >> a;

			if (sum < 0)
				sum = a;
			else
				sum += a;

			ans = max(sum, ans);
		}

		cout << ans;
	}

	return 0;
}