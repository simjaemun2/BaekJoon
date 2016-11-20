#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>

using namespace std;

#define MAX_N 1000000

typedef long long int LL;

int N,M;
int input[MAX_N+1];

bool isCuttable(int sawLength)
{
	LL sum = 0;
	for (int i = 0; i < N; i++)
	{
		if (input[i] > sawLength)
			sum += input[i] - sawLength;
	}

	return sum >= M;
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif


	cin >> N >> M;

	int l = 0;
	int r = 0;
	int m;

	int ans = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> input[i];
		
		if (input[i] > r)
			r = input[i];
	}
	
	while (l <= r)
	{
		m = l + (r - l) / 2;

		if (isCuttable(m))
		{
			if (ans < m)
				ans = m;
			l = m + 1;
		}
		else
		{
			r = m - 1;
		}

	}

	cout << ans;


	return 0;
}