#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string>
#include <vector>

using namespace std;

int N;

bool cmp(const string &a, const string &b)
{
	if (a.size() == b.size())
	{
		return a < b;
	}

	return a.size() < b.size();
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

		vector<string> v(N);

		for (int i = 0; i<N; i++)
		{
			cin >> v[i];
		}

		sort(v.begin(), v.end(), cmp);

		cout << v[0] << endl;

		for (int i = 1; i<N; i++)
		{
			if(v[i-1] != v[i])
				cout << v[i] << endl;
		}
	}

	return 0;
}