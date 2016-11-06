#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string>

using namespace std;

#define MAX_N 4000

int N;
int cache[MAX_N + 10][MAX_N + 10];
int choice[MAX_N + 10];
string A, B;
int lenA, lenB;


int solve(int a, int b)
{
	if (a == lenA || b == lenB)
		return 0;
	int &ret = cache[a+1][b+1];

	if (ret != -1)
		return ret;

	ret = 0;

	if (A[a] == B[b])
	{
		ret = 1 + solve(a + 1, b + 1);
	}

	return ret;
}

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
		cin >> A >> B;
		lenA = A.length();
		lenB = B.length();

		memset(cache, -1, sizeof(cache));

		//string s = "";

		int ans = 0;

		for (int i = 0; i < lenA; i++)
		{
			for (int j = 0; j < lenB; j++)
			{
				ans = max(ans, solve(i, j));
			}
		}

		cout << ans;

		//cout << solve(-1, -1) << endl;
		//reconstruct(0, 0, s);
		//cout << s;
	}

	return 0;
}