#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

#define MAX_N 50


int N, M;
int ans;
typedef long long int LL;

LL src[MAX_N];
LL dst[MAX_N];

void push(int y, int x)
{
	LL xx = 7LL << x;
	for (int i = 0; i < 3; i++)
	{
		src[y + i] ^= xx;
	}
}

bool check()
{
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = 0; j < M - 2; j++)
		{
			if (((src[i] >> j) & 1) != ((dst[i] >> j) & 1))
			{
				push(i, j);
				ans++;
			}
		}
		if (src[i] != dst[i])
		{
			return false;
		}
	}

	if (src[N - 2] != dst[N - 2] || src[N - 1] != dst[N - 1])
		return false;
	return true;
}

void getInput(LL* input)
{
	char c;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			input[i] <<= 1;
			cin >> c;
			if (c == '1')
				input[i]++;
		}
	}
}

int main(int argc, char** argv)
{

	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	cin >> N >> M;

	getInput(src);
	getInput(dst);

	if (!check())
		cout << -1;
	else
		cout << ans;

	return 0;
}