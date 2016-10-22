#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>


using namespace std;

#define MAX_N 100
int N;
int cache[MAX_N + 1];
vector<pair<int, int> > v;

int solve()
{
	for (int i = 0; i < N-1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (v[i].second < v[j].second && cache[i] + 1 > cache[j])
				cache[j] = 1 + cache[i];
		}
	}

	int ret = cache[0];

	for (int i = 1; i < N; i++)
		ret = max(ret, cache[i]);

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
		cin >> N;

		for (int i = 0; i<N; i++)
		{
			int a, b;
			cin >> a >> b;
			
			cache[i] = 1;

			v.push_back(pair<int, int>(a, b));
		}

		sort(v.begin(), v.end());

		cout << (N-solve()) << endl;
	}

	return 0;
}