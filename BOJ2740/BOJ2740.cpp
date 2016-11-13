#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>


using namespace std;

#define MAX_N 100

int N,M,K;
int A[MAX_N][MAX_N];
int B[MAX_N][MAX_N];
int C[MAX_N][MAX_N];

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
		cin >> N >> M;
		
		for (int i = 0; i<N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> A[i][j];
			}
		}

		cin >> M >> K;

		for (int i = 0; i<M; i++)
		{
			for (int j = 0; j < K; j++)
			{
				cin >> B[i][j];
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int k = 0; k < M; k++)
			{
				for (int j = 0; j < K; j++)
				{
					C[i][j] += A[i][k] * B[k][j];
				}
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < K; j++)
			{
				cout << C[i][j] << " ";
			}
			cout << endl;
		}

	}

	return 0;
}