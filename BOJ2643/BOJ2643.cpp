#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <functional>

using namespace std;

#define MAX_N 100
#define INF 2000000000
#define MOD

int N;
int cache[MAX_N + 1];



void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
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
		cin >> N;

		vector<pair<int, int> > v(N);

		for (int i = 0; i<N; i++)
		{
			cin >> v[i].first >> v[i].second;
			
			if (v[i].first < v[i].second)
				swap(v[i].first, v[i].second);

			cache[i] = 1;
		}

		sort(v.begin(), v.end(), greater<pair<int, int> >());

		for (int i = 0; i < N - 1; i++)
		{
			for (int j = i + 1; j < N; j++)
			{
				if (v[i].first >= v[j].first && v[i].second >= v[j].second
					&& cache[i] + 1 > cache[j])
					cache[j] = cache[i] + 1;
			}
		}

		int ans = cache[0];

		for (int i = 1; i < N; i++)
			ans = max(ans, cache[i]);

		cout << ans;
	}

	return 0;
}