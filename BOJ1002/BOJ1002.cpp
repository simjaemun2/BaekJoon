#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>

using namespace std;

struct node {
	int y, x, r;
};

node n1, n2;

int solve()
{
	node small, big;

	if (n1.x == n2.x && n1.y == n2.y && n1.r == n2.r)
		return -1;

	if (n1.r > n2.r) small = n2,big = n1;
	else small = n1, big = n2;

	int d = (small.x - big.x)*(small.x - big.x) + (small.y - big.y)*(small.y - big.y);

	if (d < big.r*big.r) //inside
	{
		if (d == (big.r - small.r)*(big.r - small.r))
			return 1;
		else if (d < (big.r - small.r)*(big.r - small.r))
			return 0;
		else
			return 2;
	}
	else if (d > big.r*big.r)//outside
	{
		if ((small.r + big.r)*(small.r + big.r) == d)
			return 1;
		else if ((small.r + big.r)*(small.r + big.r) > d)
			return 2;
		else return 0;
	}
	else
	{
		return 2;
	}
}

int main(int argc, char** argv)
{
	int tc, T;
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	cin >> T;
	for (tc = 0; tc < T; tc++)
	{
		cin >> n1.x >> n1.y >> n1.r >> n2.x >> n2.y >> n2.r;

		cout << solve() << endl;
	}

	return 0;
}