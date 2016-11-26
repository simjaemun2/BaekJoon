#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>

using namespace std;

#define MAX_N 100000


int N;
char input[MAX_N + 1];

int main(int argc, char** argv)
{
	int tc, T;
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	cin >> input;
	int ans = 0;
	int stack = 0;
	bool stacked = false;
	for(int i=0; input[i]; i++)
	{
		switch (input[i])
		{
		case '(':
			stacked = true;
			stack++;
			break;
		
		case ')':
			stack--;
			if (stacked)
			{
				ans += stack;
				stacked = false;
			}
				
			else
				ans += 1;
			break;
		}
			
	}
	cout << ans;

	return 0;
}