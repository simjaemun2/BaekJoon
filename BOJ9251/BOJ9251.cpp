#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string>

using namespace std;

#define MAX_N 1000

int N;
int cache[MAX_N + 10][MAX_N + 10];
int choice[MAX_N + 10];
string A, B;
int lenA, lenB;


int solve(int a, int b)
{
	if (a == lenA || b == lenB)
		return 0;
	int &ret = cache[a][b];

	if (ret != -1)
		return ret;

	ret = 0;

	int aBestNext = -1;


	if (A[a] == B[b])
	{
		ret = 1 + solve(a + 1, b + 1);
	}
	else
	{
		ret = max(solve(a, b + 1), solve(a + 1, b));
	}

	choice[a] = aBestNext;

	return ret;
}

void reconstruct(int a, int b, string& s)
{
	if (a == lenA || b == lenB)
		return;

	if (A[a] == B[b])
	{
		s += A[a];
		reconstruct(a + 1, b + 1, s);
	}
	else
	{
		if (cache[a][b] == cache[a + 1][b])
			reconstruct(a + 1, b, s);
		else
			reconstruct(a, b + 1, s);
	}
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

		cout << solve(0, 0) << endl;
		//reconstruct(0, 0, s);
		//cout << s;
	}

	return 0;
}