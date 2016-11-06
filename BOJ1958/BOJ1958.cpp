#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string>

using namespace std;

#define MAX_N 100

int N;
int cache[MAX_N + 10][MAX_N + 10][MAX_N + 10];
string A, B, C;
int lenA, lenB,lenC;


int solve(int a, int b, int c)
{
	if (a == lenA || b == lenB || c == lenC)
		return 0;
	int &ret = cache[a][b][c];

	if (ret != -1)
		return ret;

	ret = 0;


	if (A[a] == B[b] && B[b] == C[c])
	{
		ret = 1 + solve(a + 1, b + 1, c+1);
	}
	else
	{
		ret = max(solve(a + 1, b, c), solve(a, b + 1, c));
		ret = max(ret, solve(a, b, c + 1));
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
		cin >> A >> B >> C;
		lenA = A.length();
		lenB = B.length();
		lenC = C.length();

		memset(cache, -1, sizeof(cache));

		//string s = "";

		cout << solve(0, 0, 0) << endl;
		//reconstruct(0, 0, s);
		//cout << s;
	}

	return 0;
}