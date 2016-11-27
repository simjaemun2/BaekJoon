#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N;
int a;
int nPush;
int i;

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	scanf("%d", &N);

	stack<int> s;
	vector<char> v;

	s.push(-1);
	for (i = 0; i<N; i++)
	{
		scanf("%d", &a);

		if (nPush < a)
		{
			for (int i = nPush; i < a; i++)
			{
				nPush++;
				v.push_back('+');
				s.push(nPush);
			}
		}

		if (s.top() != a)
		{
			break;
		}
		else
		{
			v.push_back('-');
			s.pop();
		}
	}


	if (i == N)
	{
		for (int i = 0; i < v.size(); i++)
		{
			printf("%c\n", v[i]);
		}
	}
	else
	{
		printf("%s\n", "NO");
	}

	return 0;
}