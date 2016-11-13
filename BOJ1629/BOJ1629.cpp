#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>

using namespace std;

long long int A,B,C;

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

		long long int ans = 1;

		while (B > 0)
		{
			if (B & 1)
			{
				ans *= A;
				ans %= C;
			}

			A *= A;
			A %= C;

			B /= 2;
		}

		cout << ans;
	}

	return 0;
}