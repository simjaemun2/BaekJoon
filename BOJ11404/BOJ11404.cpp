#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>


using namespace std;

#define MAX_N 100
#define INF 20000000

int input[MAX_N + 1][MAX_N + 1];

int N, M;
int A, B, C;

int main(int argc, char** argv)
{

	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			input[i][j] = INF;
		}
		input[i][i] = 0;
	}

	for (int i = 0; i<M; i++)
	{
		cin >> A >> B >> C;

		if (input[A][B] > C)
		{
			input[A][B] = C;
		}
	}

	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (input[i][k] + input[k][j] < input[i][j])
				{
					input[i][j] = input[i][k] + input[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << input[i][j] << " ";
		}
		cout << endl;
	}


	return 0;
}