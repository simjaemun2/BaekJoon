#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int L,C;


void solve(vector<char>& v, int start, string s)
{
	if (start >= C && s.size() != L)
		return;

	if (s.size() == L)
	{

		int vowelCount = 0;
		int consonantCount = 0;

		for (int i = 0; i < s.size(); i++)
		{
			switch (s[i])
			{
			case 'a': case 'e': case 'i': case 'o': case 'u':
				vowelCount++;
				break;
			default:
				consonantCount++;
			}
		}

		if (consonantCount >= 2 && vowelCount >= 1)
		{
			//cout << "start : " << start << "  cur : " << cur << endl;
			cout << s << endl;
		}
		return;
	}

	solve(v, start + 1, s + v[start]);
	solve(v, start + 1, s);
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
		cin >> L >> C;

		vector<char > v(C);

		for (int i = 0; i < C; i++)
		{
			cin >> v[i];
		}

		sort(v.begin(), v.end());

		solve(v,0, "");
	}

	return 0;
}