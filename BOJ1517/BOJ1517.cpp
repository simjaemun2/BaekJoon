#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>

using namespace std;

typedef long long int LL;

#define MAX_N 500000

int N;
int input[MAX_N];
int tmp[MAX_N];

LL countMoves(int l, int r)
{
	if (l == r)
		return 0;

	int mid = (l + r) / 2;

	LL ret = countMoves(l, mid) + countMoves(mid + 1, r);

	int ti = 0, li = l, ri = mid + 1;

	while (li <= mid || ri <= r)
	{
		if (li <= mid && (ri > r || input[li] <= input[ri]))
		{
			tmp[ti++] = input[li++];
		}
		else
		{
			ret += mid - li + 1;
			tmp[ti++] = input[ri++];
		}
	}

	for (int i = 0; i < r - l + 1; i++)
		input[l + i] = tmp[i];

	return ret;
}

int main(int argc, char** argv)
{

	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> input[i];
	}

	cout << countMoves(0, N - 1);

	return 0;
}