#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>


using namespace std;

#define MAX_N 50


int N;
char input[MAX_N + 1];

int solve()
{
	int ret = 0;

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
			cin >> input;

			int index = 0;

			int cnt = 0;
			bool breakable = false;
			while (input[index] && !breakable)
			{
				switch (input[index])
				{
				case '(':
					cnt++;
					break;
				case ')':
					if (cnt == 0)
						breakable = true;
					cnt--;
					break;
				}

				index++;
			}

			if (cnt != 0 || breakable)
			{
				cout << "NO" << endl;
			}
			else
			{
				cout << "YES" << endl;
			}
		}
	}

	return 0;
}