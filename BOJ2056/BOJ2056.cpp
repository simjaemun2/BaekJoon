#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;

#define MAX_N 10000

int N;
int cache[MAX_N + 1];
int ans;
int t, c, a;

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
	cin >> N;

	
	for (int i = 1; i <= N; i++)
	{
		
		cin >> t >> c;

		for (int j = 0; j < c; j++)
		{
			cin >> a;
			if (cache[i] < cache[a])
				cache[i] = cache[a];

		}
		cache[i] += t;
		if (ans < cache[i])
			ans = cache[i];
	}

	cout << ans;


	return 0;
}